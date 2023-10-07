// dz_8_5.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "dz_8_5.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DZ85, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DZ85));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DZ85));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DZ85);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void drawHome(HDC hdc) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 15, RGB(500, 200, 75));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 150, 350, NULL);
    LineTo(hdc, 275, 250);
    LineTo(hdc, 400, 350);

    LineTo(hdc, 400, 525);
    LineTo(hdc, 150, 525);
    LineTo(hdc, 150, 350);
    LineTo(hdc, 400, 350);

    MoveToEx(hdc, 225, 400, NULL);
    LineTo(hdc, 225, 475);
    LineTo(hdc, 325, 475);
    LineTo(hdc, 325, 400);
    LineTo(hdc, 225, 400);

    MoveToEx(hdc, 275, 400, NULL);
    LineTo(hdc, 275, 475);
    MoveToEx(hdc, 275, 425, NULL);
    LineTo(hdc, 325, 425);
}

void drawTree(HDC hdc) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 5, RGB(50, 350, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 450, 525, NULL);
    LineTo(hdc, 525, 450);
    LineTo(hdc, 600, 525);
    LineTo(hdc, 450, 525);

    MoveToEx(hdc, 475, 450, NULL);
    LineTo(hdc, 525, 400);
    LineTo(hdc, 575, 450);
    LineTo(hdc, 475, 450);

    MoveToEx(hdc, 500, 400, NULL);
    LineTo(hdc, 525, 375);
    LineTo(hdc, 550, 400);
    LineTo(hdc, 500, 400);
}

void drawCar(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(128, 0, 0));
    SelectObject(hdc, hPen);
    HBRUSH hBrush;
    hBrush = CreateSolidBrush(RGB(255, 128, 67));
    SelectObject(hdc, hBrush);

    Rectangle(hdc, 50, 200, 300, 250);

    MoveToEx(hdc, 100, 200, NULL);
    LineTo(hdc, 150, 150);
    LineTo(hdc, 250, 150);
    LineTo(hdc, 300, 200);

    hPen = CreatePen(PS_SOLID, 7, RGB(0, 0, 128));
    SelectObject(hdc, hPen);
    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(255, 0, 0));
    SelectObject(hdc, hBrush);

    Ellipse(hdc, 75, 225, 125, 275);

    hPen = CreatePen(PS_SOLID, 7, RGB(0, 128, 0));
    SelectObject(hdc, hPen);
    hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 255, 0));
    SelectObject(hdc, hBrush);

    Ellipse(hdc, 225, 225, 275, 275);

}

void drawSnowman(HDC hdc) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(80, 80, 80));
    SelectObject(hdc, hPen);
    HBRUSH hBrush;
    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(800, 800, 800));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 425, 225, 575, 300);
    Ellipse(hdc, 450, 175, 550, 225);
    Ellipse(hdc, 475, 125, 525, 175);

    hPen = CreatePen(PS_SOLID, 3, RGB(150, 75, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 450, 200, NULL);
    LineTo(hdc, 425, 200);
    LineTo(hdc, 415, 160);
    MoveToEx(hdc, 550, 200, NULL);
    LineTo(hdc, 575, 200);
    LineTo(hdc, 600, 220);

    hPen = CreatePen(PS_SOLID, 2, RGB(243, 93, 35));
    SelectObject(hdc, hPen);
    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(243, 93, 35));
    MoveToEx(hdc, 500, 150, NULL);
    LineTo(hdc, 465, 150);
    LineTo(hdc, 455, 160);
    LineTo(hdc, 470, 155);
    LineTo(hdc, 500, 150);
}

void drawBush1(HDC hdc) {
    int x3 = 400, y3 = 150;
    int x4 = 500, y4 = 250;
    do {
        MoveToEx(hdc, x3, y3, NULL);
        LineTo(hdc, x4, y4);
        x3 += 25;
    } while (x3 <= 600);

}

void drawBush2(HDC hdc) {
    int x5 = 0, y5 = 250;
    int x6 = 100, y6 = 250;
    do {
        MoveToEx(hdc, x5, y5, NULL);
        LineTo(hdc, x6, y6);
        x5 += 25;
        y5 -= 50;
    } while (x5 <= 100);

    x5 = 100;
    y5 = 50;
    do {
        MoveToEx(hdc, x5, y5, NULL);
        LineTo(hdc, x6, y6);
        x5 += 25;
        y5 += 50;
    } while (x5 <= 200);

}

void drawFence(HDC hdc) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, RGB(450, 150, 300));
    SelectObject(hdc, hPen);
    int a1 = 150, b1 = 0;
    int a2 = 150, b2 = 100;
    do {
        MoveToEx(hdc, a1, b1, NULL);
        LineTo(hdc, a2, b2);
        a1 += 25;
        a2 += 25;
    } while (a1 <= 450);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            drawCar(hdc);

            drawBush1(hdc);

            drawBush2(hdc);

            drawHome(hdc);

            drawSnowman(hdc);

            drawTree(hdc);

            drawFence(hdc);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
