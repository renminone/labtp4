#pragma once
#include <iostream>
#include <conio.h>
#include "List.h"

using namespace std;

void Task2()
{
	List<int> A, B, U;
	int z = 1, x, y, i, n;
	cout << "Меню: " << endl;
	cout << "1 - Добавление узла в список." << endl;
	cout << "2 - Удаление узла из списка." << endl;
	cout << "3 - []." << endl;
	cout << "4 - +." << endl;
	cout << "0 - выход." << endl;
	
	while (z != 0)
	{
		switch (_getch())
		{
		case '1': cin >> x; cin >> y; A.append(x); B.append(y); break;
		case '2': A.remove(); B.remove(); break;
		case '3': cin >> i; cout << A[i] << " " << B[i] << endl; break;
		case '4': A += B; cout << A; break;
		case '0': z = 0; break;
		}
	}
}
