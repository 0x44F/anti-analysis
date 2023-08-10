#include <windows.h>
#include <stdio.h>

bool __AmIBeingDebugged() 
{
    HMODULE ntdll = GetModuleHandleA("ntdll.dll");
    if (ntdll == NULL)
        return false;

    NtSetInformationThread_t NtSetInformationThread = (NtSetInformationThread_t)GetProcAddress(ntdll, "NtSetInformationThread");
    if (NtSetInformationThread == NULL)
        return false;

    NTSTATUS status = NtSetInformationThread(GetCurrentThread(), 0x11, 0, 0);
    if (status == 0xC0000022)
        return true;
    else
        return false;
}
