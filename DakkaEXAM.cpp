#include "includes.h"

int main()
{
    //кодировки
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //фиксированный размер окна
    HWND consoleWindow = GetConsoleWindow();
    LONG_PTR windowStyle = GetWindowLongPtr(consoleWindow, GWL_STYLE);
    windowStyle = windowStyle & ~WS_THICKFRAME;
    SetWindowLongPtr(consoleWindow, GWL_STYLE, windowStyle);

    //убираем мигание курсора
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);

    //размер окна консоли
    system("mode con cols=122 lines=50");

   //проверка на существование файла
    if (!file_exist(1))
    {
        CreateDirectory(L"product_info", NULL);
        add_product();
    }
    menu();
}