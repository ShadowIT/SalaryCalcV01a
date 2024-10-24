
// SalaryCalcV01aDlg.h: файл заголовка
//

#pragma once

#include <map>

// Диалоговое окно CSalaryCalcV01aDlg
class CSalaryCalcV01aDlg : public CDialogEx
{
// Создание
public:
	CSalaryCalcV01aDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SALARYCALCV01A_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHelpAbout();
	CEdit ebOklad;
	double ebdOklad;
	double vdRK;
	CEdit cdRK;
	afx_msg void OnBnClickedButton1();
	CEdit cdItog;
	double vdItog;
	double vdPrem;
	CEdit cdPrem;
	double vdVredn;
	CEdit cdVredn;
	double vdEdViplat;
	CEdit cdEdViplat;
	double vdItogClear;
	CEdit cdItogClear;
	double vdWorkHours;
	CEdit cdWordHours;
	double vdHours;
	CEdit cdHours;
	double inHour;
	CEdit cinHour;
	COleDateTime dvDate;
	CDateTimeCtrl cdDate;
	afx_msg void OnBnClickedButton2();
	CString vList;
	CListBox cList;

	std::map<CString, double> overtimeCnt;
	


	afx_msg void OnBnClickedButton3();
	double dvTest;
	CEdit cdTest;
	BOOL vbTax;
	CButton cdTax;
	CEdit csOklad;
	afx_msg void OnBnClickedCheck1();
	double dvZam;
	CEdit cdZam;
	double dvZamHour;
	CEdit cdZamHour;
	CString vsFieldOklad;
	CEdit csFieldOklad;
	afx_msg void OnBnClickedButton4();
};

	//	Объявление формулы расчёта "грязной" ЗП по окладу
double salary_calc(double _oklad, double _rk, double _premia, double _vrednost,
	double _edVip, double _salaryInHours, double _overtimeCnt, double _doplatOts,
	double _doplatOtsHours, double _workHours);

	//	Объявление формулы расчёта "гразной" ЗП по тарифу
double salary_calc_tax(double _oklad, double _rk, double _premia, double _vrednost,
	double _edVip, double _salaryInHours, double _overtimeCnt, double _doplatOts, double _doplatOtsHours, double _workHours);

	//	Объявление формулы расчёта "чистой" ЗП
double salary_clear(double _salary);

	//	Объявление формулы расчёта "чистой" ЗП в час
double salary_clear_inHour(double _oklad, double _premia, double _rk, double _workHours, bool _tax);

double overtime_count(std::map<CString, double> _overtimeDate, double _salaryInHours, COleDateTime& _dvDate);