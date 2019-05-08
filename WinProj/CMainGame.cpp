#include "stdafx.h"
#include "CMainGame.h"
#include "CTestScene.h"
CMainGame::CMainGame()
{
	srand(time(NULL));
}


CMainGame::~CMainGame()
{

}

void CMainGame::Init()
{
	SCENE.AddScene("S_TEST", new CTestScene()); // ¾À Ãß°¡
	SCENE.ChangeScene("S_TEST"); // ¾À º¯°æ
}

void CMainGame::Update()
{
	INPUT.Update();
	SCENE.Update();
}

void CMainGame::Render()
{
	IMAGE.Begin();
	
	SCENE.Render();

	IMAGE.End();
}
void CMainGame::Release()
{
	CImageManager::ReleaseInst();
	CSceneManager::ReleaseInst();
	CInputManager::ReleaseInst();
}
