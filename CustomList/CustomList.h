
// CustomList.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCustomListApp:
// �� Ŭ������ ������ ���ؼ��� CustomList.cpp�� �����Ͻʽÿ�.
//

class CCustomListApp : public CWinApp
{
public:
	CCustomListApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCustomListApp theApp;
