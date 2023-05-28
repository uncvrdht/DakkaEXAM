#pragma once
#ifndef PROCESS_H
#define PROCESS_H

int MAX = 1;
vector<product> base;

int add_product()
{
    base.push_back(new_product());
    return MAX + 1;
}

void change()
{
    int* id = new int(0);
    goto_xy(40, 12); cout << "������� ID ������ ������ ��� ������ > "; var_cin(id, "���������� ������ ���������� ID", MAX, 1);
    base[*id - 1] = new_product(*id, true);
}

void remove()
{
    int* id = new int(0);
    goto_xy(40, 25); cout << "������� ID ������ ��� �������� > "; var_cin(id, "���������� ������ ���������� ID", MAX, 1);
    base.erase(base.begin() + *id - 1);

    stringstream filePath;
    filePath << "product_info/" << *id << ".pb";
    remove(filePath.str().c_str());

    for (int i = *id + 1; i <= MAX; i++)
    {
        stringstream oldPath, newPath;
        oldPath << "product_info/" << i << ".pb";
        newPath << "product_info/" << i - 1 << ".pb";
        rename(oldPath.str().c_str(), newPath.str().c_str());
    }

    MAX--;
}

void gallery(vector<product> base, int MAX)
{
    system("cls"); int v;
    int currentPage = 0;
    int selectedItem = 0;
    static byte sort_price = 0;
    static byte sort_group = 0;

    while (true)
    {
        system("cls");
        set_color_console(DarkGray, Black);
        cout << setw(30) << "���������� �� ���������:";
        cout << setw(30) << "-> ��������� ��������";
        cout << setw(30) << "<- ���������� ��������";
        cout << setw(30) << "ESC - ����� � ����" << endl << endl;
        set_color_console(LightCyan, Black);
        cout << setw(5) << "ID" << setw(25) << "��������" << setw(35) << "�������������" << setw(10) << "����" << setw(20) << "���" << setw(13) << "�����������" << setw(13) << "�. ��������" << endl << endl;
        set_color_console(White, Black);

        for (int i = currentPage * 45; i < (currentPage + 1) * 45 && (i * 45) < MAX; i++)
        {
            for (int j = i * 45; j < ((i + 1) * 45) && j < MAX - 1; j++) cout << base[j];
            goto_xy(10, 49); cout << "H/N - ���� �����������/��������\t" << "J/M - ������ �����������/��������\t\t"; cout << "�������� " << i + 1;
        }

        v = _getch();
        switch (v)
        {
        case LEFT:
            if (currentPage > 0)
            {
                currentPage--;
                selectedItem = (currentPage + 1) * 50 - 1;
            }
            else
            {
                selectedItem = currentPage * 50;
            }
            break;

        case RIGHT:
            if ((currentPage + 1) * 50 < MAX)
            {
                currentPage++;
                selectedItem = currentPage * 50;
            }
            else
            {
                selectedItem = (currentPage + 1) * 50 - 1;
            }
            break;        
        case ESC:
            return;
        }
        switch (v)
        {
        case H_KEY_1: case H_KEY_2: case H_KEY_3: case H_KEY_4:
            if (sort_price != 1) {
                set_color_console(Red, Black); string_center("���������, ���� ���������� ���� �� �����������!", 3);
                std::sort(base.begin(), base.end(), [](const product& a, const product& b) {
                    return a.get_price() < b.get_price(); }); sort_price = 1;
                set_color_console(White, Black);
            } break;
        case J_KEY_1: case J_KEY_2: case J_KEY_3: case J_KEY_4:
            if (sort_group != 1) {
                set_color_console(Red, Black); string_center("���������, ���� ���������� ����� �� �����������!", 3);
                std::sort(base.begin(), base.end(), [](const product& a, const product& b) {
                    return a.get_group() < b.get_group(); }); sort_group = 1;
                set_color_console(White, Black);
            } break;
        case N_KEY_1: case N_KEY_2: case N_KEY_3: case N_KEY_4:
            if (sort_price != 2) {
                set_color_console(Red, Black); string_center("���������, ���� ���������� ���� �� ��������!", 3);
                std::sort(base.begin(), base.end(), [](const product& a, const product& b) {
                    return a.get_price() > b.get_price(); }); sort_price = 2;
                set_color_console(White, Black);
            } break;
        case M_KEY_1: case M_KEY_2: case M_KEY_3: case M_KEY_4:
            if (sort_group != 2) {
                set_color_console(Red, Black); string_center("���������, ���� ���������� ����� �� ��������!", 3);
                std::sort(base.begin(), base.end(), [](const product& a, const product& b) {
                    return a.get_group() > b.get_group(); }); sort_group = 2;
                set_color_console(White, Black);
            } break;
        }
    }
}

void find()
{
    system("cls");
    vector <product> result;
    int ind; char cs[256]; int new_MAX = 1;
    
    system("cls"); int v = 0;
    string_center("����� �� ��������", 15);
    string_center("����� �� �������������", 16);
    string_center("����� �� ����", 17);
    string_center("����� �� ������", 18);
    string_center("����� �� �����������", 19);
    string_center("����� �� ����� ��������", 20);
    set_color_console(DarkGray, Black);
    string_center("ESC ��� ������ � ����", 22);
    set_color_console(White, Black);
    goto_xy(45, 15);
    cout << "->";

    while (_getch() != ENTER)
    {
        switch (_getch())
        {
        case UP:
            v--; if (v < 0) v = 0;
            break;
        case DOWN:
            v++; if (v > 5) v = 5;
            break;
        case ESC:
            return;
        }
        for (int i = 0; i < 6; i++)
        {
            goto_xy(47, 15 + i);
            cout << "\b \b\b ";
        }
        goto_xy(45, 15 + v);
        cout << "->";
    }

    goto_xy(25, 25);
    set_color_console(DarkGray, Black);
    cout << "������� �������� ��� ������ >\t";
    cin.getline(cs, 256, '\n');

    string_center("���������! ���� �����!", 27); 
    set_color_console(White, Black);
    for (int i = 0; i < MAX-1; i++)
    {
        switch (v)
        {
        case 0:
            if (base[i].name == cs) { result.push_back(base[i]); new_MAX++; }; break;
        case 1:
            if (base[i].manufactorier == cs) { result.push_back(base[i]); new_MAX++; }; break;
        case 2:
            if ((int) base[i].price == stoi(cs)) { result.push_back(base[i]); new_MAX++; }; break;
        case 3:
            if (base[i].group == cs) { result.push_back(base[i]); new_MAX++; }; break;
        case 4:
            if (base[i].arrival == cs) { result.push_back(base[i]); new_MAX++; }; break;
        case 5:
            if (base[i].before_date == cs) { result.push_back(base[i]); new_MAX++; }; break;
        }
    }

    if (!result.empty()) gallery(result, new_MAX);
    else 
    {
        set_color_console(DarkGray, Black);
        string_center("����������� ���! ESC ��� �����������", 29);
        set_color_console(White, Black);
        while (_getch() != ESC) {};
    }
    
    system("cls");
}

void menu()
{
    string_center("��������...", 25);
    while (true)
    {
        if (file_exist(MAX))
        {
            product temp;
            base.push_back(temp.read_product(MAX));
            MAX++;
        }
        else break;
    }

    if (!base.empty())
    {
        while (true)
        {
            system("cls"); int v = 0;
            string_center("�������� �������", 14);
            string_center("�������� �������", 16);
            string_center("�������� ����", 17);
            string_center("����� ������", 18);
            string_center("������ ������", 19);
            string_center("�������� ������", 20);
            set_color_console(DarkGray, Black);
            string_center("ESC ��� ������", 22);
            set_color_console(White, Black);
            goto_xy(45, 16);
            cout << "->";
            while (_getch() != 13)
            {
                switch (_getch())
                {
                case UP:
                    v--; if (v < 0) v = 0;
                    break;
                case DOWN:
                    v++; if (v > 4) v = 4;
                    break;
                case 27:
                    system("cls");
                    exit(0);
                }
                for (int i = 0; i < 5; i++)
                {
                    goto_xy(47, 16 + i);
                    cout << "\b \b\b ";
                }
                goto_xy(45, 16 + v);
                cout << "->";
            }
            switch (v)
            {
            case 0:
                MAX = add_product();
                break;
            case 1:
                gallery(base, MAX);
                break;
            case 2:
                find();
                break;
            case 3:
                change();
                break;
            case 4:
                remove();
                break;
            }
        }
    }
    system("cls");
    string_center("���� ������ �����������! Enter ��� ������ �� ���������", 12);
    while (_getch() != 13) {};
}

#endif