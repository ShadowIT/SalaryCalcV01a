
//+	1. Решить проблему: Если в списке переработок несколько строк, то при удалении первой строки выпадает исключение!!!
//+	2. Сделать изменение надписи "Оклад/Тариф" при нажатии CheckBox
//+	3. Реализовать кнопку "Сброс"

// SalaryCalcV01a.cpp: определяет поведение классов для приложения.
//

#include "pch.h"
#include "framework.h"
#include "SalaryCalcV01a.h"
#include "SalaryCalcV01aDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSalaryCalcV01aApp

BEGIN_MESSAGE_MAP(CSalaryCalcV01aApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Создание CSalaryCalcV01aApp

CSalaryCalcV01aApp::CSalaryCalcV01aApp()
{
	// поддержка диспетчера перезагрузки
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CSalaryCalcV01aApp

CSalaryCalcV01aApp theApp;


// Инициализация CSalaryCalcV01aApp

BOOL CSalaryCalcV01aApp::InitInstance()
{

	// InitCommonControlsEx() требуется для Windows XP, если манифест
	// приложения использует ComCtl32.dll версии 6 или более поздней версии для включения
	// стилей отображения.  В противном случае будет возникать сбой при создании любого окна.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Выберите этот параметр для включения всех общих классов управления, которые необходимо использовать
	// в вашем приложении.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// Создать диспетчер оболочки, в случае, если диалоговое окно содержит
	// представление дерева оболочки или какие-либо его элементы управления.
	CShellManager *pShellManager = new CShellManager;

	// Активация визуального диспетчера "Классический Windows" для включения элементов управления MFC
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Стандартная инициализация
	// Если эти возможности не используются и необходимо уменьшить размер
	// конечного исполняемого файла, необходимо удалить из следующих
	// конкретных процедур инициализации, которые не требуются
	// Измените раздел реестра, в котором хранятся параметры
	// TODO: следует изменить эту строку на что-нибудь подходящее,
	// например на название организации
	SetRegistryKey(_T("Shadow's Group"));

	CSalaryCalcV01aDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Введите код для обработки закрытия диалогового окна
		//  с помощью кнопки "ОК"
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Введите код для обработки закрытия диалогового окна
		//  с помощью кнопки "Отмена"
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Предупреждение. Не удалось создать диалоговое окно, поэтому работа приложения неожиданно завершена.\n");
		TRACE(traceAppMsg, 0, "Предупреждение. При использовании элементов управления MFC для диалогового окна невозможно #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Удалить диспетчер оболочки, созданный выше.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Поскольку диалоговое окно закрыто, возвратите значение FALSE, чтобы можно было выйти из
	//  приложения вместо запуска генератора сообщений приложения.
	return FALSE;
}

	//	Формула расчёта "гразной" ЗП по окладу
double salary_calc(double _oklad, double _rk, double _premia, double _vrednost, 
	double _edVip, double _salaryInHours, double _overtimeCnt, double _doplatOts, double _doplatOtsHours, double _workHours) {

	return (_oklad * (1.00 + _premia / 100.00) 
		+ ((_doplatOtsHours * (_oklad * (_doplatOts / 100))) / _workHours))
		* (1.00 + (_rk / 100)) * (1.00 + (_vrednost / 100)) + _edVip + _overtimeCnt;
}
	//	Формула расчёта "гразной" ЗП по тарифу
double salary_calc_tax(double _oklad, double _rk, double _premia, double _vrednost,
	double _edVip, double _salaryInHours, double _overtimeCnt, double _doplatOts, double _doplatOtsHours, double _workHours) {

	return (_oklad * _workHours + ((_doplatOtsHours * (_oklad * (_doplatOts / 100))) / _workHours)) * (1.00 + ((_premia / 100.00) + (_vrednost / 100.00)))
		* (1.00 + _rk / 100.00) + _edVip + _overtimeCnt;
}

	//	Формула расчёта "чистой" ЗП
double salary_clear(double _salary) {

	return _salary * 0.87;
}

double salary_clear_inHour(double _oklad, double _premia, double _rk, double _workHours, bool _tax) {
	double temp_d;
	if(_tax)
		temp_d = _oklad* ((1.00 + (_premia / 100.00)) * (1.00 + _rk / 100.00));
	else
		temp_d = _oklad* ((1.00 + (_premia / 100.00)) * (1.00 + _rk / 100.00)) / _workHours;

	return temp_d;
}

double overtime_count(std::map<CString, double> _overtimeDate, double _salaryInHours, COleDateTime& _dvDate) {

	double cnt = 0;
	CString day = _T("");
	CString month = _T("");
	CString year = _T("");
	bool holiday = false;
	for (auto& c : _overtimeDate) {
		double counter = 0.0;
		counter += c.second;

		day = month = year = c.first;
		day.Delete(2, 8);
		month.Delete(0, 3);
		month.Delete(2, 5);
		year.Delete(0, 6);
		int iday = _tstoi(day);
		int imonth = _tstoi(month);
		int iyear = _tstoi(year);
		_dvDate.SetDate(iyear, imonth, iday);
		int dayOfWeek = _dvDate.GetDayOfWeek();
		if (dayOfWeek == 1 || dayOfWeek == 7)			//	Учёт выходных дней
			holiday = true;
		else
			holiday = false;
		if (holiday) {
			while (counter) {
				cnt += _salaryInHours;
				--counter;
			}
		}
		else {
			while (counter) {
				if (counter > 2) {
					cnt += _salaryInHours;
				}
				if (counter <= 2) {
					cnt += (_salaryInHours / 2);
				}
				--counter;
			}
		}
	}

	return cnt;
}