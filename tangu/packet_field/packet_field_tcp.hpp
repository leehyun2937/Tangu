﻿//
// packet_field_tcp.hpp
// Copyright © jynis2937, all rights reserved,
// This program is under the GNU Lesser General Public License.
//

#pragma once
#ifndef _PACKETFIELD_TCP
#define _PACKETFIELD_TCP

#include <net_manager\net_manager.hpp>

NAMESPACE_BEGIN(Packet)

#pragma pack(push, 1)
/*
* @brief    packet_field section that supports TCP field.
*/
typedef struct _TCP_HEADER
{

	enum class Port
	{
		FTPData = 20,
		FTPControl = 21,
		Telnet = 23,
		SMTP = 25,
		
		HTTP = 80,
		POP3 = 110,
		SNMP = 161,
	};
	unsigned __int16		SrcPort;
	unsigned __int16		DstPort;
	
	unsigned __int32		Sequence;
	unsigned __int32		Acknowledgemnet;

#define TCP_OFFSET(x)				(((x / 4) << 12) & 0xF000)
#define TCP_FLAGS_NONCE		(1 << 8)
#define TCP_FLAGS_CWR			(1 << 7)
#define TCP_FLAGS_ECN			(1 << 6)
#define TCP_FLAGS_URG			(1 << 5)
#define TCP_FLAGS_ACK			(1 << 4)
#define TCP_FLAGS_PSH			(1 << 3)
#define TCP_FLAGS_RST			(1 << 2)
#define TCP_FLAGS_SYN			(1 << 1)
#define TCP_FLAGS_FIN				(1)
	unsigned __int16		FHL;
	unsigned __int16		WindowSize;

	unsigned __int16		Checksum;
	unsigned __int16		UrgentPointer;

	// Except TCP Option : (x - 20) bytes

} TCP_HEADER, *PTCP_HEADER;

NAMESPACE_END /* Packet */

#endif /* _PACKETFIELD_TCP */