// SilentWebsiteVisitor.cpp : Defines the entry point for the console application.
//

#include <Windows.h>
#include <string>
#include <thread>

using namespace std;

//CREATE_NO_WINDOW

// Return 0 is success
int SilentWebsiteVisitor(string TargetWebsite)
{
	TargetWebsite = "C:\\Program Files\\internet explorer\\iexplore.exe " + TargetWebsite;

	STARTUPINFOA si = {};
	PROCESS_INFORMATION pi = {};
	if (CreateProcessA(NULL, (LPSTR)const_cast<char *>(TargetWebsite.c_str()) , NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi) == 0)
		return 1;

	Sleep(30000);

	if (TerminateProcess(pi.hProcess, 0) == 0)
		return 2;

	if (CloseHandle(pi.hProcess) == 0)
		return 3;

	if (CloseHandle(pi.hThread) == 0)
		return 4;

	return 0;
}


int main()
{
    SilentWebsiteVisitor("http://google.com/");

    return 0;
}

