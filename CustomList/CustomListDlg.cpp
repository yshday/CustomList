#include "stdafx.h"
#include "CustomList.h"
#include "CustomListDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

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
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CCustomListDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CCustomListDlg::OnBnClickedButtonInsert)
END_MESSAGE_MAP()


BOOL CCustomListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

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
	SetWindowTheme(m_list.GetSafeHwnd(), L"Explorer", 0);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}


void CCustomListDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


HCURSOR CCustomListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCustomListDlg::OnBnClickedButtonDelete()
{
	m_list.DeleteAllItems();
}


void CCustomListDlg::OnBnClickedButtonInsert()
{
	m_list.InsertItem(0, L"0", 0);
	m_list.SetItemText(0, 1, L"50");
	m_list.InsertItem(1, L"1", 1);
	m_list.SetItemText(1, 1, L"70");
	m_list.InsertItem(2, L"2", 2);
	m_list.SetItemText(2, 1, L"100");
}
