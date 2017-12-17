
// CustomListDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "ProgressList.h"


// CCustomListDlg ��ȭ ����
class CCustomListDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CCustomListDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CUSTOMLIST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	ProgressList m_list;
	//CListCtrl m_list;
	CImageList m_imageList;
};
