#include <iostream>
using namespace std;

void Print(int **array, int rows, int cols)
{
	cout << "Вывод массива: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << array[i][j]<<"\t";
		}
		cout << endl;
	}
}

void Deleting(int** array, int rows, int cols, int k)
{
	int excess_cols = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (array[i][j] == k)
			{
				for (int i1 = 0; i1 < rows; i1++)
				{
					for (int j1 = j; j1 < cols - 1; j1++)
					{
						array[i1][j1] = array[i1][j1 + 1];
					}
				}
				excess_cols++;
			}
		}
	}
	Print(array, rows, cols - excess_cols);
}


int main()
{
	system("color F0");
	setlocale(0, "");
	int rows,cols,k;
	
	rows = 0;
	while (rows <= 0)
	{
		cout << "Введите количество строк: ";
		cin >> rows;
	}
	
	cols = 0;
	while (cols <= 0)
	{
		cout << "Введите количество столбцов: ";
		cin >> cols;
	}
	
	int** array = new int*[rows];
	
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[cols];
	}
	
	for (int i = 0; i < rows; i++)
	{
		cout << "Введите " << i + 1 << " строку: ";
		for (int j = 0; j < cols; j++)
		{
			cin >> array[i][j];
		}
		cout << endl;
	}
	
	Print(array, rows, cols);
	
	k = -1;
	while (k < 0)
	{
		cout << "Введите число, в соответствии с которым будут удаляться столбцы: ";
		cin >> k;
	}

	Deleting(array, rows, cols, k);

	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;

	return 0;
}

