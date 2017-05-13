// tvfw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "guid.h"

void usage(LPCWSTR);
int createExceptionRule(LPCWSTR);
int deleteExceptionRule();
void showFilter(const FWPM_FILTER *filter);

int wmain(int argc, WCHAR *argv[])
{
	if (argc == 3 && wcscmp(argv[1], L"create") == 0) {
		return createExceptionRule(argv[2]);
	} else if (argc == 2 && wcscmp(argv[1], L"delete") == 0)	{
		return deleteExceptionRule();
	} else {
		usage(argv[0]);
		return 1;
	}
}

void usage(LPCWSTR argv0)
{
	fwprintf(stderr,
		L"Usage:\n\n    %s create PATH: Create exception rule for PATH\n"
		L"    %s delete: Delete exception rule\n\n", argv0, argv0);
}

struct FwpmSession
{
	FwpmSession()
		: m_valid(false)
		, m_session(NULL)
	{
		if (FwpmEngineOpen(NULL, RPC_C_AUTHN_DEFAULT, NULL, NULL, &m_session) == ERROR_SUCCESS) {
			m_valid = true;
		}
	}

	~FwpmSession()
	{
		if (m_valid) {
			FwpmEngineClose(m_session);
		}
	}

	operator HANDLE() const { return m_session; }
	bool valid() const { return m_valid; };

private:
	bool m_valid;
	HANDLE m_session;
};

int deleteExceptionRule()
{
	FwpmSession hFwEngine;
	if (!hFwEngine.valid()) {
		wprintf(L"FwpmEngineOpen() failed\n");
		return 1;
	}

	DWORD dwRes = FwpmFilterDeleteByKey(hFwEngine, &TVFW_FILTER_KEY);
	if (dwRes == ERROR_SUCCESS) {
		wprintf(L"Deleted exception rule.\n");
		return 0;
	} else {
		wprintf(L"FFDBK() failed with %u\n", dwRes);
		return 1;
	}
}

int createExceptionRule(LPCWSTR teamViewerServiceExe)
{
	FwpmSession hFwEngine;
	if (!hFwEngine.valid()) {
		wprintf(L"FwpmEngineOpen() failed\n");
		return 1;
	}

	// Ensure we do not create the rule twice.
	FWPM_FILTER *filter = NULL;
	DWORD dwRes = FwpmFilterGetByKey(hFwEngine, &TVFW_FILTER_KEY, &filter);
	if (dwRes == ERROR_SUCCESS) {
		FwpmFreeMemory((void**)&filter);
		wprintf(L"TeamViewer Exception rule already exists.\n");
		return 0;
	}

	// Check all "block" rules for the "Block Outbound Default Rule".
	FWPM_FILTER_ENUM_TEMPLATE tmpl{ 0 };
	tmpl.layerKey = FWPM_LAYER_ALE_AUTH_CONNECT_V4;
	tmpl.flags = FWP_FILTER_ENUM_FLAG_SORTED | FWP_FILTER_ENUM_FLAG_INCLUDE_BOOTTIME;
	tmpl.actionMask = FWP_ACTION_BLOCK;

	HANDLE hEnum = NULL;
	dwRes = FwpmFilterCreateEnumHandle(hFwEngine, &tmpl, &hEnum);
	if (dwRes != ERROR_SUCCESS) {
		wprintf(L"FFCEH() failed with %u\n", dwRes);
		return 1;
	}

	FWPM_FILTER **entries = NULL;
	UINT32 count = 0;

	dwRes = FwpmFilterEnum(hFwEngine, hEnum, 4, &entries, &count);
	if (dwRes != ERROR_SUCCESS) {
		wprintf(L"FFE(1) failed with %u\n", dwRes);
		return 1;
	}

	UINT64 annoyingRuleId = 0;
	UINT64 annoyingRuleWeight = 0;

	while (count > 0) {
		for (FWPM_FILTER **p = entries; count > 0; ++p, --count) {
			//showFilter(*p);

			// If we find the rule, remember its weight for later.
			if (wcscmp((*p)->displayData.name, L"Block Outbound Default Rule") == 0) {
				annoyingRuleId = (*p)->filterId;
				annoyingRuleWeight = *(*p)->effectiveWeight.uint64;
				goto leave;
			}
		}

		FwpmFreeMemory((void**)&entries);
		entries = NULL;

		dwRes = FwpmFilterEnum(hFwEngine, hEnum, 4, &entries, &count);
		if (dwRes != ERROR_SUCCESS) {
			wprintf(L"FFE(ff) failed with %u\n", dwRes);
			return 1;
		}
	}

leave:

	dwRes = FwpmFilterDestroyEnumHandle(hFwEngine, hEnum);
	if (dwRes != ERROR_SUCCESS) {
		wprintf(L"FFDEH() failed with %u\n", dwRes);
		return 1;
	}

	// If the problematic rule exists, create a new one that allows TV,
	// with a higher weight so it is evaluated first.
	if (annoyingRuleId != 0) {
		FWPM_FILTER newFilter;
		ZeroMemory(&newFilter, sizeof(FWPM_FILTER));

		newFilter.filterKey = TVFW_FILTER_KEY;
		newFilter.displayData.description = L"TeamViewer Exception";
		newFilter.displayData.name = L"TeamViewer Exception";

		// FWPM_FILTER_FLAG_CLEAR_ACTION_RIGHT may not be necessary because
		// the problematic rule is not evaluated after this rule permits 
		// the connection.
		newFilter.flags = FWPM_FILTER_FLAG_PERSISTENT | FWPM_FILTER_FLAG_CLEAR_ACTION_RIGHT;

		newFilter.layerKey = FWPM_LAYER_ALE_AUTH_CONNECT_V4;

		UINT64 weight = annoyingRuleWeight + 1;
		newFilter.weight.type = FWP_UINT64;
		newFilter.weight.uint64 = &weight;
		newFilter.numFilterConditions = 1;
		
		FWPM_FILTER_CONDITION cond;
		ZeroMemory(&cond, sizeof(FWPM_FILTER_CONDITION));

		cond.fieldKey = FWPM_CONDITION_ALE_APP_ID;
		cond.matchType = FWP_MATCH_EQUAL;

		FWP_BYTE_BLOB *appId = NULL;
		dwRes = FwpmGetAppIdFromFileName(teamViewerServiceExe, &appId);
		if (dwRes != ERROR_SUCCESS) {
			wprintf(L"FGAIFF() failed with %u\n", dwRes);
			return 1;
		}
		cond.conditionValue.type = FWP_BYTE_BLOB_TYPE;
		cond.conditionValue.byteBlob = appId;

		newFilter.filterCondition = &cond;
		newFilter.action.type = FWP_ACTION_PERMIT;

		UINT64 newFilterId = 0;
		dwRes = FwpmFilterAdd(hFwEngine, &newFilter, NULL, &newFilterId);
		if (dwRes == ERROR_SUCCESS) {
			wprintf(L"Added new filter with runtime ID %I64u, weight %#I64x\n", newFilterId, weight);
		} else {
			wprintf(L"FFA() failed with %u\n", dwRes);
			return 1;
		}

		FwpmFreeMemory((void**)&appId);
	}

	return 0;
}
