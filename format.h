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
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
    case '�': r = '�'; break;
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
void var_cin(T* var, string message = "���������� �����", T max_v = 10000, T min_v = 0)
{
    cin >> *var;
    while (cin.fail() || *var > max_v || *var < min_v)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cin.sync();
        if (*var > max_v)
        {
            cout << "\t����� ����������� �������! ������������ ����� - " << max_v << endl;
            cout << "\t���������� �����: ";
        }
        else if (*var < min_v)
        {
            cout << "\t����� ����������� ���������! ����������� ����� - " << min_v << endl;
            cout << "\t���������� �����: ";
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