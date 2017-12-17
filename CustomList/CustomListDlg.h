#pragma once
#include "afxcmn.h"
#include "ProgressList.h"


class CCustomListDlg : public CDialogEx
{
public:
	CCustomListDlg(CWnd* pParent = NULL);

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CUSTOMLIST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);


protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonInsert();

	DECLARE_MESSAGE_MAP()

private:
	ProgressList m_list;
	CImageList m_imageList;

	
};
