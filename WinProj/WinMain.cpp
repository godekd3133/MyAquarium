// WinProj.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "WinProj.h"
#include "CSystem.h"
#include <crtdbg.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	AllocConsole();
	freopen("CONOUT$", "a", stdout);
	freopen("CONOUT$", "a", stderr);
	freopen("CONIN$", "r", stdin); 
#endif

	RECT rtSystemSize = { 1920/2 - WINSIZEX/2, 1080/2 - WINSIZEY/2, 1920/2 +WINSIZEX/2 , 1080/2 +WINSIZEY/2 };

	SYSTEM.WinInit(L"20105 김민규");
	
	SYSTEM.WinCreate(L"20105 김민규", L"20105 김민규", hInst, WS_OVERLAPPEDWINDOW, rtSystemSize);

	SYSTEM.Run();

	CSystem::ReleaseInst();

	FreeConsole();

	return 0;
}