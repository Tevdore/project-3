#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <windows.h>

#include <calculation.c>
#include <postfix.c>
#include <function1.c>

int __stdcall WinMain (HINSTANCE h, HINSTANCE h1, char *cmd, int mode)
{
WNDCLASS wc={0};
MSG msg;
HWND hwnd;

ULONG clr=RGB(12,100,100);
	if(*cmd)
	clr=atoi(cmd);

wc.hbrBackground=CreateSolidBrush(RGB(0,150,100));
wc.lpfnWndProc=(WNDPROC)proc_main_wnd; //wc.lpfnWndProc=DefWindowProc;
wc.lpszClassName="AA123";	

	if(!RegisterClass(&wc))
	{
	UINT er=GetLastError();
	return 1;
	}


hwnd=CreateWindow("AA123",cmd
				   ,WS_VISIBLE|WS_OVERLAPPEDWINDOW
				   |WS_HSCROLL
				   |WS_BORDER
				   |WS_THICKFRAME
				   ,100,100,410,400,0,0,0,0);

//CreateWindow("edit", "EDIT Control",WS_VISIBLE|WS_CHILD,10,10,100,30,hwnd,(HMENU)1,0,0);
//CreateWindow("button","BUTTON Control",WS_VISIBLE|WS_CHILD,100,70,70,70,hwnd,(HMENU)2,0,0);
//CreateWindow("static","STATIC Control",WS_VISIBLE|WS_CHILD,10,100,100,60,hwnd,(HMENU)3,0,0);
while(1)
{
GetMessage(&msg,hwnd,0,0);
TranslateMessage(&msg);
DispatchMessage(&msg);
}
}	
