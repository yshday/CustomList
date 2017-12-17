
// CustomListDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "CustomList.h"
#include "CustomListDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCustomListDlg 대화 상자



CCustomListDlg::CCustomListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CUSTOMLIST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCustomListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CCustomListDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CCustomListDlg 메시지 처리기

BOOL CCustomListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	VERIFY(m_imageList.Create(24, 24, ILC_COLOR32, 0, 0));
	auto inst = AfxGetInstanceHandle();
	BOOL bRes = m_imageList.Add(LoadIcon(inst, (LPCTSTR)IDI_SUN));
	bRes = m_imageList.Add(LoadIcon(inst, (LPCTSTR)IDI_LIGHTNING));
	bRes = m_imageList.Add(LoadIcon(inst, (LPCTSTR)IDI_MOON));

	m_list.SetImageList(&m_imageList, LVSIL_SMALL);

	m_list.InsertColumn(0, L"index", LVCFMT_LEFT, 100, 0);
	m_list.InsertColumn(1, L"progress", LVCFMT_LEFT, 100, 1);

	m_list.InsertItem(0, L"0", 0);
	m_list.SetItemText(0, 1, L"50");
	m_list.InsertItem(1, L"1", 1);
	m_list.SetItemText(1, 1, L"70");
	m_list.InsertItem(2, L"2", 2);
	m_list.SetItemText(2, 1, L"100");

	m_list.SetProgressColumn(1);

	//LVITEM lvi;
	//lvi.iItem = 0;
	//lvi.iSubItem = 0;
	//lvi.mask = LVIF_IMAGE;
	//lvi.iImage = 1;
	//m_list.SetItem(&lvi);


	//m_list.SetItem(0, 0, LVIF_TEXT | LVIF_IMAGE, L"test", 0, NULL, NULL, 0, 0);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCustomListDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCustomListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

