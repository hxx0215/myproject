#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>
#include <iostream> 
#include<string>
#include <tchar.h>
#include <shlwapi.h>
#pragma comment(lib,"User32.lib")
#pragma comment(lib, "shlwapi.lib")

BYTE* GetWoWBaseAddress(int ProcessID)
{
        MODULEENTRY32 lmpe;
        lmpe.dwSize = sizeof(MODULEENTRY32);
        HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,ProcessID);
        //lmpe.dwSize=sizeof(hSnapModule32Firstshot);
        BYTE* wowbase;
        if (Module32First(hSnapshot,&lmpe)!=0)
        {
                do 
                {
                        
                                wowbase=lmpe.modBaseAddr;
                                printf("\r\n path : %s\r\n base : %x\r\n", lmpe.szExePath, lmpe.modBaseAddr);
								
                        
                        Sleep(10);

                } while (Module32Next(hSnapshot,&lmpe));
        }
        return wowbase;
}
int main()
{
	HWND hWnd=FindWindow(NULL,"Ä§ÊÞÊÀ½ç");
	DWORD Pid;
	GetWindowThreadProcessId(hWnd,&Pid);
	GetWoWBaseAddress(Pid);
	int i;
	scanf("%d",&i);
	return 0;
}