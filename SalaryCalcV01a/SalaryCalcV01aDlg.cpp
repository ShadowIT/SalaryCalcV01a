
// SalaryCalcV01aDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "SalaryCalcV01a.h"
#include "SalaryCalcV01aDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButton1)
END_MESSAGE_MAP()

// Диалоговое окно CSalaryCalcV01aDlg

CSalaryCalcV01aDlg::CSalaryCalcV01aDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SALARYCALCV01A_DIALOG, pParent)
	, ebdOklad(0)
	, vdRK(25)
	, vdItog(0)
	, vdPrem(30)
	, vdVredn(0)
	, vdEdViplat(0)
	, vdItogClear(0)
	, vdWorkHours(160)
	, vdHours(1)
	, inHour(0)
	, dvDate(COleDateTime::GetCurrentTime())
	, vList(_T(""))
	, dvTest(0)
	, vbTax(FALSE)
	, dvZam(0)
	, dvZamHour(0)
	, vsFieldOklad(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSalaryCalcV01aDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, ebOklad);
	DDX_Text(pDX, IDC_EDIT1, ebdOklad);
	DDX_Text(pDX, IDC_EDIT2, vdRK);
	DDV_MinMaxDouble(pDX, vdRK, 0, 100);
	DDX_Control(pDX, IDC_EDIT2, cdRK);
	DDX_Control(pDX, IDC_EDIT7, cdItog);
	DDX_Text(pDX, IDC_EDIT7, vdItog);
	DDX_Text(pDX, IDC_EDIT3, vdPrem);
	DDV_MinMaxDouble(pDX, vdPrem, 0, DBL_MAX);
	DDX_Control(pDX, IDC_EDIT3, cdPrem);
	DDX_Text(pDX, IDC_EDIT4, vdVredn);
	DDV_MinMaxDouble(pDX, vdVredn, 0, 100);
	DDX_Control(pDX, IDC_EDIT4, cdVredn);
	DDX_Text(pDX, IDC_EDIT5, vdEdViplat);
	DDV_MinMaxDouble(pDX, vdEdViplat, 0, DBL_MAX);
	DDX_Control(pDX, IDC_EDIT5, cdEdViplat);
	DDX_Text(pDX, IDC_EDIT8, vdItogClear);
	DDX_Control(pDX, IDC_EDIT8, cdItogClear);
	DDX_Text(pDX, IDC_EDIT6, vdWorkHours);
	DDV_MinMaxDouble(pDX, vdWorkHours, 0, DBL_MAX);
	DDX_Control(pDX, IDC_EDIT6, cdWordHours);
	DDX_Text(pDX, IDC_EDIT9, vdHours);
	DDV_MinMaxDouble(pDX, vdHours, 0, DBL_MAX);
	DDX_Control(pDX, IDC_EDIT9, cdHours);
	DDX_Text(pDX, IDC_EDIT10, inHour);
	DDX_Control(pDX, IDC_EDIT10, cinHour);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, dvDate);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, cdDate);
	DDX_LBString(pDX, IDC_LIST1, vList);
	DDX_Control(pDX, IDC_LIST1, cList);
	DDX_Text(pDX, IDC_EDIT11, dvTest);
	DDX_Control(pDX, IDC_EDIT11, cdTest);
	DDX_Check(pDX, IDC_CHECK1, vbTax);
	DDX_Control(pDX, IDC_CHECK1, cdTax);
	DDX_Control(pDX, IDC_BUTTON1, csOklad);
	DDX_Text(pDX, IDC_EDIT12, dvZam);
	DDV_MinMaxDouble(pDX, dvZam, 0, 100);
	DDX_Control(pDX, IDC_EDIT12, cdZam);
	DDX_Text(pDX, IDC_EDIT13, dvZamHour);
	DDV_MinMaxDouble(pDX, dvZamHour, 0, 300);
	DDX_Control(pDX, IDC_EDIT13, cdZamHour);
	DDX_Text(pDX, IDC_EDIT14, vsFieldOklad);
	DDX_Control(pDX, IDC_EDIT14, csFieldOklad);
}

BEGIN_MESSAGE_MAP(CSalaryCalcV01aDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_HELP_ABOUT, &CSalaryCalcV01aDlg::OnHelpAbout)
	ON_BN_CLICKED(IDC_BUTTON1, &CSalaryCalcV01aDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSalaryCalcV01aDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSalaryCalcV01aDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK1, &CSalaryCalcV01aDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON4, &CSalaryCalcV01aDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// Обработчики сообщений CSalaryCalcV01aDlg

BOOL CSalaryCalcV01aDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	csFieldOklad.SetWindowTextW(L"Оклад (руб)");

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CSalaryCalcV01aDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CSalaryCalcV01aDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CSalaryCalcV01aDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSalaryCalcV01aDlg::OnHelpAbout()
{
	// TODO: добавьте свой код обработчика команд
	CDialog aDlg(IDD_ABOUTBOX);
	aDlg.DoModal();
}

void CAboutDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	
}

void CSalaryCalcV01aDlg::OnBnClickedButton1()			//	Кнопка Рассчёт
{														//	Считывание данных с полей ввода
	CString temp_str = _T("");
	ebOklad.GetWindowTextW(temp_str);
	double oklad = round(_tstof(temp_str) * 100) / 100;
	cdRK.GetWindowTextW(temp_str);
	double rk = round(_tstof(temp_str) * 100) / 100;
	cdPrem.GetWindowTextW(temp_str);
	double prem = round(_tstof(temp_str) * 100) / 100;
	cdVredn.GetWindowTextW(temp_str);
	double vredn = round(_tstof(temp_str) * 100) / 100;
	cdEdViplat.GetWindowTextW(temp_str);
	double edViplat = round(_tstof(temp_str) * 100) / 100;
	cdWordHours.GetWindowTextW(temp_str);
	double workHours = round(_tstof(temp_str) * 100) / 100;
	cdZam.GetWindowTextW(temp_str);
	double doplatOts = round(_tstof(temp_str) * 100) / 100;
	cdZamHour.GetWindowTextW(temp_str);
	double doplatOtsHour = round(_tstof(temp_str) * 100) / 100;
	bool tax = cdTax.GetCheck();
	double salaryInHours = round(salary_clear_inHour(oklad, prem, rk, workHours, tax) * 100) / 100;
	double overtimeVal = 0.0;
	double overtimeValToOklad = 0.0;
	for (auto& c : overtimeCnt)
		oklad += c.second;		
	double d_overtimeCnt = round(overtime_count(overtimeCnt, salaryInHours, dvDate) * 100) / 100;
	d_overtimeCnt = round(d_overtimeCnt * 100) / 100;
	double salary = 0.0;
	if (tax)
		salary = round(salary_calc_tax(oklad, rk, prem, vredn, edViplat, salaryInHours, 
			d_overtimeCnt, doplatOts, doplatOtsHour, workHours) * 100) / 100;
	else
		salary = round(salary_calc(oklad, rk, prem, vredn, edViplat, salaryInHours,
			d_overtimeCnt, doplatOts, doplatOtsHour, workHours) * 100) / 100;
	double salaryClear = round(salary_clear(salary) * 100) / 100;
	temp_str.Format(_T("%.2f"), salary);
	cdItog.SetWindowTextW(temp_str);					//	Вывод грязной ЗП в поле "Итог"
	temp_str.Format(_T("%.2f"), salaryClear);				//	Форматирование числа для вывода
	cdItogClear.SetWindowTextW(temp_str);				//	Вывод чистой ЗП в поле "На руки"	
	if(tax)
		temp_str.Format(_T("%.2f"), round((oklad * (1.00 + prem / 100.00) * (1.00 + rk / 100.00)) * 100) / 100);
	else
		temp_str.Format(_T("%.2f"), round(salaryInHours * 100) / 100);
	cinHour.SetWindowTextW(temp_str);	
	temp_str.Format(_T("%.2f"), d_overtimeCnt);
	cdTest.SetWindowTextW(temp_str);
}

void CSalaryCalcV01aDlg::OnBnClickedButton2()			//	Кнопка Добавить
{
	CString temp_str = _T("");
	CString sDate = _T("");
	CString temp_str_1 = _T("");
	CString temp_space = _T("     ");
	cdDate.GetWindowTextW(temp_str);
	cdHours.GetWindowTextW(temp_str_1);

	sDate = temp_str;
	bool dublikat = false;

	for (auto& c :overtimeCnt) {
		if (c.first == sDate) {
			dublikat = true;
		}
	}
	if (!dublikat) {

		temp_str += temp_space + temp_str_1;
		int index = cList.AddString(temp_str);
		double hours = _tstof(temp_str_1);

		overtimeCnt[sDate] = hours;

	}
}

void CSalaryCalcV01aDlg::OnBnClickedButton3()			//	Кнопка Удалить
{
	int index = cList.GetCurSel();
	CString date = _T("");
	
	cList.GetText(index, date);
	date.Delete(10, 10);

	overtimeCnt.erase(date);

	cList.DeleteString(index);
	
}

void CSalaryCalcV01aDlg::OnBnClickedCheck1()			//	Чекбокс Тариф
{
	CString temp_str = _T("");
	bool tax = cdTax.GetCheck();
	if (tax)
		temp_str = "Тариф (руб)";
	else
		temp_str = "Оклад (руб)";
	csFieldOklad.SetWindowTextW(temp_str);
}

void CSalaryCalcV01aDlg::OnBnClickedButton4()			//	Кнопка Кнопка Сброс
{
	CString temp_str = _T("");
	temp_str.Format(_T("%i"), 0);
	ebOklad.SetWindowTextW(temp_str);
	cdRK.SetWindowTextW(temp_str);
	cdPrem.SetWindowTextW(temp_str);
	cdVredn.SetWindowTextW(temp_str);
	cdEdViplat.SetWindowTextW(temp_str);
	cdWordHours.SetWindowTextW(temp_str);
	cdZam.SetWindowTextW(temp_str);
	cdZamHour.SetWindowTextW(temp_str);
	cdItog.SetWindowTextW(temp_str);
	cdItogClear.SetWindowTextW(temp_str);
	cinHour.SetWindowTextW(temp_str);
	cdHours.SetWindowTextW(temp_str);
	cdTest.SetWindowTextW(temp_str);
	overtimeCnt.clear();
	cList.ResetContent();
}
