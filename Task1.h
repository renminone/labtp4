#pragma once
#include <iostream>
#include <conio.h>
#include "Shablon.h"
using namespace std;

void Task1()
{
    setlocale(LC_ALL, "Rus");
    int f = 1, x;
    Sort<int> arr;
    arr.fill();

    cout << "Меню:" << endl;
    cout << "1 - добавление элемента." << endl;
    cout << "2 - удаление элемента." << endl;
    cout << "3 - сортировка по возрастанию." << endl;
    cout << "4 - сортировака по убыванию." << endl;
    cout << "5 - вывод массива на экран" << endl;
    cout << "0 - выход." << endl << endl;

    while (f != 0)
    {
        switch (_getch())
        {
        case '1': cin >> x; arr.add(x); cout << "Добавлено успешно!" << endl; break;
        case '2': arr.del(); cout << "Удалено успешно!" << endl; break;
        case '3': arr.rise(); break;
        case '4': arr.fall(); break;
        case '5': arr.output(); break;
        case '0': arr.clean(); f = 0; break;
        }
    }

}
