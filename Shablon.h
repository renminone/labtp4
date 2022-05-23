#pragma once
#include <iostream>

using namespace std; 

template<class Type>
class Sort
{
	Type* p;
	int size;
public:
	void fill()
	{
		cin >> size;
		p = new Type[size];
		for (int i = 0; i < size; i++)
			cin >> p[i];
	}

	void add(Type x)
	{
		Type* temp = new Type[size];
		for (int i = 0; i < size; i++) temp[i] = p[i];
		delete p; size++; p = new Type [size];
		for (int i = 0; i < size - 1; i++) p[i] = temp[i];
		p[size - 1] = x;
	}

	void del()
	{
		Type* temp = new Type[size-1];
		for (int i = 0; i < size-1; i++) temp[i] = p[i];
		delete p; size--; p = new Type [size];
		for (int i = 0; i < size; i++) p[i] = temp[i];
	}

	int sizeback() { return size; }
	Type rise()
	{
		int n = sizeback();
		int i = 0, j = 0;
		Type* xj = new Type[n];
		Type temp;
		for (i = 0; i < n; i++) xj[i] = p[i];
		
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - i - 1; j++)
			{
				if (xj[j] > xj[j + 1])
				{
					// меняем элементы местами
					temp = xj[j];
					xj[j] = xj[j + 1];
					xj[j + 1] = temp;
				}
			}
		}

		for (i = 0; i < n; i++) cout << xj[i] << " ";
		cout << endl;
		return *xj;
	}

	Type fall()
	{
		int n = sizeback();
		int i = 0, j = 0;
		Type* ry = new Type[n];
		Type temp;
		for (i = 0; i < n; i++) ry[i] = p[i];

		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - i - 1; j++)
			{
				if (ry[j] < ry[j + 1])
				{
					// меняем элементы местами
					temp = ry[j];
					ry[j] = ry[j + 1];
					ry[j + 1] = temp;
				}
			}
		}

	for (i = 0; i < n; i++) cout << ry[i] << " ";
	cout << endl;
	return *ry;
	}
	
	void output()
	{
		int n = sizeback();
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl << endl;
	}

	void clean()
	{
		delete[] p;
		size = 0;
	}
};

int rise(int* p, int size);
int fall(int* p, int size);
