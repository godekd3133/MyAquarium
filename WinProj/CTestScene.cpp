#include "stdafx.h"
#include "CTestScene.h"
#include "CFish.h"
#include "CAmp.h"
#include "CAngie.h"
#include "COctopus.h"
#include "CBlip.h"
#include "CItchy.h"

CTestScene::CTestScene()
{
}


CTestScene::~CTestScene()
{
}

void CTestScene::Init()
{
	IMAGE.AddTexture("BACKGROUND", "./resource/Bg/Bg1.bmp");
	IMAGE.AddTexture("AMP", "./resource/Fish/amp/amp.bmp");
	IMAGE.AddTexture("AMP_REVERSE", "./resource/Fish/amp/amp_reverse.bmp");
	IMAGE.AddTexture("ANGIE", "./resource/Fish/angie/angie.bmp");
	IMAGE.AddTexture("ANGIE_REVERSE", "./resource/Fish/angie/angie_reverse.bmp");
	IMAGE.AddTexture("OCTOPUS", "./resource/Fish/Octopus/Octopus.bmp");
	IMAGE.AddTexture("OCTOPUS_REVERSE", "./resource/Fish/Octopus/Octopus_reverse.bmp");
	IMAGE.AddTexture("BLIP", "./resource/Fish/Blip/Blip.bmp");
	IMAGE.AddTexture("BLIP_REVERSE", "./resource/Fish/Blip/Blip_reverse.bmp");
	IMAGE.AddTexture("ITCHY", "./resource/Fish/Itchy/Itchy.bmp");
	IMAGE.AddTexture("ITCHY_REVERSE", "./resource/Fish/Itchy/Itchy_reverse.bmp");


	m_Fishes.push_back(new CAmp());
	m_Fishes.push_back(new CAngie());
	m_Fishes.push_back(new COctopus());
	m_Fishes.push_back(new CBlip());
	m_Fishes.push_back(new CItchy());

	for (auto& iter : m_Fishes)
	{
		iter->Init();
	}
}

void CTestScene::Update()
{
	for (auto& iter : m_Fishes)
	{
		iter->Update();
	}
}

void CTestScene::Render()
{
	IMAGE["BACKGROUND"]->Render({0,0}, RGB(0, 0, 0));
	for (auto& iter : m_Fishes)
	{
		iter->Render();
	}
}

void CTestScene::Release()
{
	for (auto& iter : m_Fishes)
	{
		iter->Release();
		SAFE_DELETE(iter);
	}
	m_Fishes.clear();
}
