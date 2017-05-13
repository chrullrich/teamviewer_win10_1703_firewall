#pragma once

#define INITGUID
#include <guiddef.h>

// The filter rule is declared FWPM_FILTER_FLAG_PERSISTENT, i.e. it is
// reinstated after a reboot. We need a fixed key so we can prevent 
// creating duplicate rules.

// {3AF576A6-4091-449D-A298-C4A1AFB64F70}
DEFINE_GUID(TVFW_FILTER_KEY,
	0x3af576a6, 0x4091, 0x449d, 0xa2, 0x98, 0xc4, 0xa1, 0xaf, 0xb6, 0x4f, 0x70);

#undef INITGUID
