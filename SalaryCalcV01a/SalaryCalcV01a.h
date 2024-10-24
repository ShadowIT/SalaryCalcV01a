
// SalaryCalcV01a.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSalaryCalcV01aApp:
// Сведения о реализации этого класса: SalaryCalcV01a.cpp
//

class CSalaryCalcV01aApp : public CWinApp
{
public:
	CSalaryCalcV01aApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CSalaryCalcV01aApp theApp;
