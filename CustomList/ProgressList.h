#pragma once
#include "afxcmn.h"
class ProgressList : public CListCtrl
{
public:
	ProgressList();
	virtual ~ProgressList();

	void SetProgressColumn(const int column);
	void SelectAllItems();
	void UnselectAllItems();

protected:

	afx_msg void OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()

private:
	int m_progressColumn = -1;
};

