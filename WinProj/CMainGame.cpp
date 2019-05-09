#include "stdafx.h"
#include "CMainGame.h"
#include "CTestScene.h"
CMainGame::CMainGame()
{
	srand(timeGetTime());
}


CMainGame::~CMainGame()
{

}

void CMainGame::Init()
{
	SOUND.AddSound("BG", "./Sound/Bg.mp3");
	SOUND.Play("BG", true);
	SCENE.AddScene("S_TEST", new CTestScene()); // �� �߰�
	SCENE.ChangeScene("S_TEST"); // �� ����
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
	CSoundManager::ReleaseInst();
}
