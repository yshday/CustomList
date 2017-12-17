#include "stdafx.h"
#include "ProgressList.h"


BEGIN_MESSAGE_MAP(ProgressList, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomDraw)
END_MESSAGE_MAP()


ProgressList::ProgressList()
{
}


ProgressList::~ProgressList()
{
}


void ProgressList::SetProgressColumn(const int column)
{
	m_progressColumn = column;
}


void ProgressList::SelectAllItems()
{
	SetItemState(-1, LVIS_SELECTED, LVIS_SELECTED);
}


void ProgressList::UnselectAllItems()
{
	SetItemState(-1, 0, LVIS_SELECTED);
}


void ProgressList::OnCustomDraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVCUSTOMDRAW* ncd = reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);
	
	*pResult = CDRF_DODEFAULT;

	switch (ncd->nmcd.dwDrawStage)
	{
	case CDDS_PREPAINT:
	{
		*pResult = CDRF_NOTIFYITEMDRAW;

		break;
	}
	case CDDS_ITEMPREPAINT:
	{
		*pResult = CDRF_NOTIFYSUBITEMDRAW;

		break;
	}
	case (CDDS_ITEMPREPAINT | CDDS_SUBITEM):
	{
		int item = static_cast<int> (ncd->nmcd.dwItemSpec);
		int subItem = ncd->iSubItem;

		LVITEM lvItem;

		if (m_progressColumn != -1 && subItem == m_progressColumn)
		{
			int cx;
			HDC hdc = ncd->nmcd.hdc;
			COLORREF clrBack;
			HBRUSH hBackBrush;
			HBRUSH hProgressBrush;
			HBRUSH hOldBrush;
			HPEN hPen;
			HPEN hOldPen;
			RECT rc;

			clrBack = ncd->clrTextBk;
			if (clrBack == CLR_NONE || clrBack == CLR_DEFAULT)
				clrBack = RGB(255, 255, 255);

			hBackBrush = CreateSolidBrush(clrBack);
			hProgressBrush = CreateSolidBrush(RGB(190, 190, 255));
			hPen = CreatePen(PS_SOLID, 0, RGB(190, 190, 255));

			hOldBrush = (HBRUSH)SelectObject(hdc, hBackBrush);
			FillRect(hdc, &ncd->nmcd.rc, hBackBrush);

			CString s = GetItemText(item, subItem);
			int per = _ttoi(s);

			cx = ncd->nmcd.rc.right - ncd->nmcd.rc.left - 6;
			if (cx < 0)
				cx = 0;
			rc.left = ncd->nmcd.rc.left + 3;
			rc.top = ncd->nmcd.rc.top + 2;
			rc.right = rc.left + cx * per / 100;
			rc.bottom = ncd->nmcd.rc.bottom - 2;
			SelectObject(hdc, hProgressBrush);
			FillRect(hdc, &rc, hProgressBrush);

			rc.right = ncd->nmcd.rc.right - 3;
			SelectObject(hdc, GetStockObject(HOLLOW_BRUSH));
			auto oldpen = SelectObject(hdc, hPen);
			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

			lvItem.iSubItem = ncd->iSubItem;
			lvItem.pszText = (LPWSTR)(LPCTSTR)s;
			SendMessage(LVM_GETITEMTEXT, ncd->nmcd.dwItemSpec, (LPARAM)&lvItem);

			s += L"%";
			DrawText(hdc, s, -1, &rc,
				DT_CENTER | DT_VCENTER | DT_NOPREFIX | DT_SINGLELINE | DT_END_ELLIPSIS);

			SelectObject(hdc, hOldBrush);
			DeleteObject(hProgressBrush);
			DeleteObject(hBackBrush);
			SelectObject(hdc, oldpen);
			DeleteObject(hPen);

			*pResult = CDRF_SKIPDEFAULT;
		}

		break;
	}
	default:
		break;
	}
}
