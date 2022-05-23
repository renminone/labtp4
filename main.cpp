#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "Task1.h"
#include "Task2.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int a = 1;
    while (a != 0)
    {
        cout << "Меню:" << endl;
        cout << "1 - задание 1." << endl;
        cout << "2 - задание 2." << endl;
        cout << "0 - выход." << endl;
        switch (_getch())
        {
        case '1': Task1(); break;
        case '2': Task2(); break;
        case '0': a = 0; break;
        }
        system("cls");
    }
    return 0;

}
