/*
 *
 *  Copyright (C) 2013  Anwar Mohamed <anwarelmakrahy[at]gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to Anwar Mohamed
 *  anwarelmakrahy[at]gmail.com
 *
 */

#pragma once
#include "Packetyzer.h"
//#include "cString.h"
//#include "cHash.h"
//#include "cFile.h"
//#include "cTCPStream.h"
#include "Packetyzer.h"

using namespace Packetyzer::Elements;

struct REQUEST
{
	UCHAR*	RequestType;
	cString*	Address;
	cHash*		Arguments;
	UINT		ReplyNumber;
};

class Packetyzer::Traffic::Streams::cHTTPStream : public Packetyzer::Traffic::Streams::cTCPStream
{
	BOOL CheckType(UCHAR* buffer);
protected:
	void AnalyzeProtocol();
public:

	static BOOL Identify(cPacket* Packet);
	BOOL AddPacket(cPacket* Packet);

	cHTTPStream(void);
	~cHTTPStream(void);

	cString** Cookies;
	UINT nCookies;

	cString* UserAgent;
	cString* Referer;
	cString* ServerType;

	cFile** Files;
	UINT nFiles;

	REQUEST* Requests;
	UINT nRequests;

	cString** Responses;
	UINT nResponses;
};
