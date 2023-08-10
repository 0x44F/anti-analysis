#include <windows.h>
#include <stdio.h>

DWORD intDetectDebug;

bool __AmIBeingDebugged()
{
    CloseHandle((HANDLE)0x1234);
    intDetectDebug = 420;

    return false;
}

int main()
{
    __AmIBeingDebugged();
    if (intDetectDebug != 420)
    {
        printf("You're being debugged!\r\n");
    }
}
