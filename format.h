#pragma once
#ifndef FORMAT_H
#define FORMAT_H

enum ConsoleColor
{
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

void set_color_console(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int MyToLower(char r)
{
    switch (r)
    {
    case 'А': r = 'а'; break;
    case 'Б': r = 'б'; break;
    case 'В': r = 'в'; break;
    case 'Г': r = 'г'; break;
    case 'Д': r = 'д'; break;
    case 'Е': r = 'е'; break;
    case 'Ё': r = 'ё'; break;
    case 'Ж': r = 'ж'; break;
    case 'З': r = 'з'; break;
    case 'И': r = 'и'; break;
    case 'Й': r = 'й'; break;
    case 'К': r = 'к'; break;
    case 'Л': r = 'л'; break;
    case 'М': r = 'м'; break;
    case 'Н': r = 'н'; break;
    case 'О': r = 'о'; break;
    case 'П': r = 'п'; break;
    case 'Р': r = 'р'; break;
    case 'С': r = 'с'; break;
    case 'Т': r = 'т'; break;
    case 'У': r = 'у'; break;
    case 'Ф': r = 'ф'; break;
    case 'Х': r = 'х'; break;
    case 'Ц': r = 'ц'; break;
    case 'Ч': r = 'ч'; break;
    case 'Ш': r = 'ш'; break;
    case 'Щ': r = 'щ'; break;
    case 'Ъ': r = 'ъ'; break;
    case 'Ы': r = 'ы'; break;
    case 'Ь': r = 'ь'; break;
    case 'Э': r = 'э'; break;
    case 'Ю': r = 'ю'; break;
    case 'Я': r = 'я'; break;
    }
    return (r);
}

string remove_rn(string n)
{
    size_t found_r = n.find('\r');
    if (found_r != string::npos)
        n.erase(found_r, 1);
    size_t found_esc = n.find(27);
    if (found_esc != string::npos)
        n.erase(found_esc, 1);
    return n;
}

string to_lower(string t)
{
    string o = "";
    for (char& c : t)
    {
        //        c = tolower(c);
        c = MyToLower(c);
        o += (char)c;
    }
    return o;
}

template <typename T>
void remove_duplicates(vector<T>& v)
{
    set<T> s;
    vector<T> res;
    for (int i = 0; i < signed(v.size()); i++)
    {
        T x = v[i];
        if (s.find(x) == s.end())
        {
            s.insert(x);
            res.push_back(x);
        }
    }
    swap(v, res);

    for (int i = 0; i < signed(v.size()); i++)
    {
        if (v[i] == "" || v[i] == " ")
        {
            v.erase(v.begin() + i);
        }
    }

}

void goto_xy(int X, int Y)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

bool file_exist(int base_number)
{
    stringstream path;
    path << "product_info/" << base_number << ".pb";
    bool exist = false;
    ifstream file(path.str());
    if (file.is_open())
        exist = true;
    file.close();
    return (exist);
}

void string_center(string str)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(h, &info);
    short x = 122 / 2 - (str.size() / 2);
    info.dwCursorPosition.X = x;
    SetConsoleCursorPosition(h, info.dwCursorPosition);
    cout << str << endl;
}

void string_center(string str, int y)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    short x = 122 / 2 - (str.size() / 2);
    COORD coord = { x, y };
    SetConsoleCursorPosition(hStdOut, coord);
    cout << str << endl;
}

template <typename T>
void var_cin(T* var, string message = "Попробуйте снова", T max_v = 10000, T min_v = 0)
{
    cin >> *var;
    while (cin.fail() || *var > max_v || *var < min_v)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cin.sync();
        if (*var > max_v)
        {
            cout << "\tЧисло недопустимо большое! Максимальное число - " << max_v << endl;
            cout << "\tПопробуйте снова: ";
        }
        else if (*var < min_v)
        {
            cout << "\tЧисло недопустимо маленькое! Минимальное число - " << min_v << endl;
            cout << "\tПопробуйте снова: ";
        }
        else
        {
            cout << message + ": ";
        }
        cin >> *var;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    cin.sync();
}

#endif