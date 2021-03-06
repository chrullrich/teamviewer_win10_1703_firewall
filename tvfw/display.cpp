#include "stdafx.h"

void printGUID(const GUID *guid)
{
	LPOLESTR s = NULL;
	StringFromCLSID(*guid, &s);
	wprintf(L"%s", s);
	CoTaskMemFree((LPVOID)s);
}

#define TRY_GUID(g, x) if (IsEqualGUID(*g, x)) { wprintf(L"%s", L#x); return; }
void printLayerName(const GUID *guid)
{
	TRY_GUID(guid, FWPM_LAYER_INBOUND_IPPACKET_V4);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_IPPACKET_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_IPPACKET_V6);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_IPPACKET_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_IPPACKET_V4);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_IPPACKET_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_IPPACKET_V6);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_IPPACKET_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_IPFORWARD_V4);
	TRY_GUID(guid, FWPM_LAYER_IPFORWARD_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_IPFORWARD_V6);
	TRY_GUID(guid, FWPM_LAYER_IPFORWARD_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_TRANSPORT_V4);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_TRANSPORT_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_TRANSPORT_V6);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_TRANSPORT_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_TRANSPORT_V4);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_TRANSPORT_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_TRANSPORT_V6);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_TRANSPORT_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_STREAM_V4);
	TRY_GUID(guid, FWPM_LAYER_STREAM_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_STREAM_V6);
	TRY_GUID(guid, FWPM_LAYER_STREAM_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_DATAGRAM_DATA_V4);
	TRY_GUID(guid, FWPM_LAYER_DATAGRAM_DATA_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_DATAGRAM_DATA_V6);
	TRY_GUID(guid, FWPM_LAYER_DATAGRAM_DATA_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_ICMP_ERROR_V4);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_ICMP_ERROR_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_ICMP_ERROR_V6);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_ICMP_ERROR_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_ICMP_ERROR_V4);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_ICMP_ERROR_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_ICMP_ERROR_V6);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_ICMP_ERROR_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_ALE_RESOURCE_ASSIGNMENT_V4);
	TRY_GUID(guid, FWPM_LAYER_ALE_RESOURCE_ASSIGNMENT_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_ALE_RESOURCE_ASSIGNMENT_V6);
	TRY_GUID(guid, FWPM_LAYER_ALE_RESOURCE_ASSIGNMENT_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_ALE_AUTH_LISTEN_V4);
	TRY_GUID(guid, FWPM_LAYER_ALE_AUTH_LISTEN_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_ALE_AUTH_LISTEN_V6);
	TRY_GUID(guid, FWPM_LAYER_ALE_AUTH_LISTEN_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_ALE_AUTH_RECV_ACCEPT_V4);
	TRY_GUID(guid, FWPM_LAYER_ALE_AUTH_RECV_ACCEPT_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_ALE_AUTH_RECV_ACCEPT_V6);
	TRY_GUID(guid, FWPM_LAYER_ALE_AUTH_RECV_ACCEPT_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_ALE_AUTH_CONNECT_V4);
	TRY_GUID(guid, FWPM_LAYER_ALE_AUTH_CONNECT_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_ALE_AUTH_CONNECT_V6);
	TRY_GUID(guid, FWPM_LAYER_ALE_AUTH_CONNECT_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_ALE_FLOW_ESTABLISHED_V4);
	TRY_GUID(guid, FWPM_LAYER_ALE_FLOW_ESTABLISHED_V4_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_ALE_FLOW_ESTABLISHED_V6);
	TRY_GUID(guid, FWPM_LAYER_ALE_FLOW_ESTABLISHED_V6_DISCARD);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_MAC_FRAME_ETHERNET);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_MAC_FRAME_ETHERNET);
	TRY_GUID(guid, FWPM_LAYER_INBOUND_MAC_FRAME_NATIVE);
	TRY_GUID(guid, FWPM_LAYER_OUTBOUND_MAC_FRAME_NATIVE);
	TRY_GUID(guid, FWPM_LAYER_INGRESS_VSWITCH_ETHERNET);
	TRY_GUID(guid, FWPM_LAYER_EGRESS_VSWITCH_ETHERNET);
	TRY_GUID(guid, FWPM_LAYER_INGRESS_VSWITCH_TRANSPORT_V4);
	TRY_GUID(guid, FWPM_LAYER_INGRESS_VSWITCH_TRANSPORT_V6);
	TRY_GUID(guid, FWPM_LAYER_EGRESS_VSWITCH_TRANSPORT_V4);
	TRY_GUID(guid, FWPM_LAYER_EGRESS_VSWITCH_TRANSPORT_V6);
	TRY_GUID(guid, FWPM_LAYER_IPSEC_KM_DEMUX_V4);
	TRY_GUID(guid, FWPM_LAYER_IPSEC_KM_DEMUX_V6);
	TRY_GUID(guid, FWPM_LAYER_IPSEC_V4);
	TRY_GUID(guid, FWPM_LAYER_IPSEC_V6);
	TRY_GUID(guid, FWPM_LAYER_IKEEXT_V4);
	TRY_GUID(guid, FWPM_LAYER_IKEEXT_V6);
	TRY_GUID(guid, FWPM_LAYER_RPC_UM);
	TRY_GUID(guid, FWPM_LAYER_RPC_EPMAP);
	TRY_GUID(guid, FWPM_LAYER_RPC_EP_ADD);
	TRY_GUID(guid, FWPM_LAYER_RPC_PROXY_CONN);
	TRY_GUID(guid, FWPM_LAYER_RPC_PROXY_IF);
	TRY_GUID(guid, FWPM_LAYER_KM_AUTHORIZATION);
	TRY_GUID(guid, FWPM_LAYER_NAME_RESOLUTION_CACHE_V4);
	TRY_GUID(guid, FWPM_LAYER_NAME_RESOLUTION_CACHE_V6);
	TRY_GUID(guid, FWPM_LAYER_ALE_RESOURCE_RELEASE_V4);
	TRY_GUID(guid, FWPM_LAYER_ALE_RESOURCE_RELEASE_V6);
	TRY_GUID(guid, FWPM_LAYER_ALE_ENDPOINT_CLOSURE_V4);
	TRY_GUID(guid, FWPM_LAYER_ALE_ENDPOINT_CLOSURE_V6);
	TRY_GUID(guid, FWPM_LAYER_ALE_CONNECT_REDIRECT_V4);
	TRY_GUID(guid, FWPM_LAYER_ALE_CONNECT_REDIRECT_V6);
	TRY_GUID(guid, FWPM_LAYER_ALE_BIND_REDIRECT_V4);
	TRY_GUID(guid, FWPM_LAYER_ALE_BIND_REDIRECT_V6);
	TRY_GUID(guid, FWPM_LAYER_STREAM_PACKET_V4);
	TRY_GUID(guid, FWPM_LAYER_STREAM_PACKET_V6);

	printGUID(guid);
}

void printSubLayerName(const GUID *guid)
{
	TRY_GUID(guid, FWPM_SUBLAYER_RPC_AUDIT);
	TRY_GUID(guid, FWPM_SUBLAYER_IPSEC_TUNNEL);
	TRY_GUID(guid, FWPM_SUBLAYER_UNIVERSAL);
	TRY_GUID(guid, FWPM_SUBLAYER_LIPS);
	TRY_GUID(guid, FWPM_SUBLAYER_SECURE_SOCKET);
	TRY_GUID(guid, FWPM_SUBLAYER_TCP_CHIMNEY_OFFLOAD);
	TRY_GUID(guid, FWPM_SUBLAYER_INSPECTION);
	TRY_GUID(guid, FWPM_SUBLAYER_TEREDO);
	TRY_GUID(guid, FWPM_SUBLAYER_IPSEC_FORWARD_OUTBOUND_TUNNEL);
	TRY_GUID(guid, FWPM_SUBLAYER_IPSEC_DOSP);
	TRY_GUID(guid, FWPM_SUBLAYER_TCP_TEMPLATES);

		printGUID(guid);
}
#undef TRY_GUID

#define TRY_FWP_DATA_TYPE(vtyp, typ, fld, fmt) if (vtyp == typ) { wprintf(fmt, fld); return; }
void printFwpValue(const FWP_VALUE *val)
{
	TRY_FWP_DATA_TYPE(val->type, FWP_EMPTY, L"(empty)", L"%s");
	TRY_FWP_DATA_TYPE(val->type, FWP_UINT8, val->uint8, L"%u");
	TRY_FWP_DATA_TYPE(val->type, FWP_UINT16, val->uint16, L"%u");
	TRY_FWP_DATA_TYPE(val->type, FWP_UINT32, val->uint32, L"%u");
	TRY_FWP_DATA_TYPE(val->type, FWP_UINT64, *val->uint64, L"%I64u");
	TRY_FWP_DATA_TYPE(val->type, FWP_INT8, val->int8, L"%d");
	TRY_FWP_DATA_TYPE(val->type, FWP_INT16, val->int16, L"%d");
	TRY_FWP_DATA_TYPE(val->type, FWP_INT32, val->int32, L"%d");
	TRY_FWP_DATA_TYPE(val->type, FWP_INT64, *val->int64, L"%I64d");
	TRY_FWP_DATA_TYPE(val->type, FWP_FLOAT, val->float32, L"%f");
	TRY_FWP_DATA_TYPE(val->type, FWP_DOUBLE, *val->double64, L"%f");

	/*
	// skip non-scalar types; too much work to implement
	FWP_BYTE_ARRAY16_TYPE,
	FWP_BYTE_BLOB_TYPE,
	FWP_SID,
	FWP_SECURITY_DESCRIPTOR_TYPE,
	FWP_TOKEN_INFORMATION_TYPE,
	FWP_TOKEN_ACCESS_INFORMATION_TYPE,
	FWP_UNICODE_STRING_TYPE,
	FWP_BYTE_ARRAY6_TYPE,
	*/

	wprintf(L"(unsupported type %u)", val->type);
}

void showFilter(const FWPM_FILTER * filter)
{
	wprintf(L"Filter %I64u:\n", filter->filterId);
	wprintf(L"filterKey: ");
	printGUID(&filter->filterKey);
	wprintf(L"\n");
	wprintf(L"name: %s\n", filter->displayData.name);
	if (filter->displayData.description != NULL) {
		wprintf(L"description: %s\n", filter->displayData.description);
	}
	wprintf(L"layer: ");
	printLayerName(&filter->layerKey);
	wprintf(L"\n");
	wprintf(L"sublayer: ");
	printSubLayerName(&filter->subLayerKey);
	wprintf(L"\n");
	wprintf(L"weight: ");
	printFwpValue(&filter->weight);
	wprintf(L"\n");
	wprintf(L"effectiveWeight: ");
	printFwpValue(&filter->effectiveWeight);
	wprintf(L"\n\n");
}
