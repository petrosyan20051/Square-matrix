#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n; // n - размер квадратной матрицы (n x n)
	
	cout << "Введите n (размер квадратной матрицы n x n) : ";
	cin >> n;
	while (n <= 0)
	{
		cout << "Введено неверное значение! Попробуйте ещё раз" << endl;
		cin >> n;
	}

	int** matrix{ new int* [n] }; // создаём начальный динамический массив со строками

	for (int temp = 0; temp < n; temp++) // добавляем в массив столбцы
		matrix[temp] = new int[n];

	for (int temp_row = 0; temp_row < n; temp_row++) // заполняем матрицу
	{
		for (int temp_column = 0; temp_column < n; temp_column++)
		{
			cout << "matrix[" << temp_row << "][" << temp_column << "] = ";
			cin >> matrix[temp_row][temp_column];
		}
	}

	
	/*
	for (int temp_row = 0; temp_row < n; temp_row++) // выводим матрицу на консоль
	{
		for (int temp_column = 0; temp_column < n; temp_column++)
		{
			cout << setw(6) << matrix[temp_row][temp_column] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	*/

	int* num{ new int[n] }; // создаём массив для сохрания чисел главной последовательности

	for (int temp_row = 0; temp_row < n; temp_row++) // заполняем num числами главной последовательности
	{
		int f = 0; // f (флаг) используем, чтобы сразу забрать значение из строки и прервать второй цикл - оптимизация скорости кода
		for (int temp_column = 0; temp_column < n; temp_column++)
		{
			if (f == 1)
				continue;
			else if (temp_row == temp_column)
			{
				num[temp_row] = matrix[temp_row][temp_column];
				f = 1;
			}
		
		}
		f = 0;
	}

	/*
	for (int temp = 0; temp < n; temp++) // выводим вектор массив
		cout << setw(6) << num[temp] << ' ';
	cout << endl << endl;
	*/

	for (int temp_column = 0; temp_column < n; temp_column++) // заменяем первую строку матрицы на вектор строку
		matrix[0][temp_column] = num[temp_column];

	
	for (int temp_row = 0; temp_row < n; temp_row++) // выводим конечную матрицу на консоль
	{
		for (int temp_column = 0; temp_column < n; temp_column++)
		{
			cout << setw(6) << matrix[temp_row][temp_column] << ' ';
		}
		cout << endl;
	}
	
	_getch();
	return 0;
}