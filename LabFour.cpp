/**
*\file
\brief Программа, определяющая симметричность матрицы относительно побочной диагонали
\author Orbly
\version 1.0
*/

#include "pch.h"
#include <iostream>
#include "locale.h"
#include <conio.h>
#include <time.h>
#include <Windows.h>

/*!
\brief Функция выполняет удаление массива
\param[in] a Динамический массив
\param[in] n Размер массива
*\code
void deleteArray(int* a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}
*\endcode
*/

void deleteArray(int* a[], int n) //Удаление массива
{
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}

/*!
\brief Функция выводит массив на экран
\param[in] a Динамический массив
\param[in] n Размер массива
*\code
void drawArray(int* a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
*\endcode
*/


void drawArray(int* a[], int n) //Вывод массива на экран
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

/*!
\brief Функция производит проверку матрицы на симметричность относительно побочной диагонали
\param[in] a Динамический массив
\param[in] n Размер массива
\param[in] sym Проверка симметричности
*\code
void processingArray(int* a[], int n, bool sym)
{
	sym = true;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != a[n - 1 - j][n - 1 - i])
			{
				sym = false;
				break;
			}
		}
		if (!sym)
		{
			break;
		}
	}

	if (sym == true)
	{
		printf("Матрица симметрична относительно побочной диагонали\n\n");
	}
	else printf("Матрица несимметрична\n\n");

}
*\endcode
*/

void processingArray(int* a[], int n, bool sym)
{
	sym = true;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != a[n - 1 - j][n - 1 - i])
			{
				sym = false;
				break;
			}
		}
		if (!sym)
		{
			break;
		}
	}

	if (sym == true)
	{
		printf("Матрица симметрична относительно побочной диагонали\n\n");
	}
	else printf("Матрица несимметрична\n\n");

}

/*!
\brief Функция ручного ввода значений матрицы
\param[in] a Динамический массив
\param[in] n Размер массива
\param[in] check Проверка вводимых данных
*\code
void manualEnter(int* a[], int n, char check)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Введите элемент [%d][%d]: ", i + 1, j + 1);
			while (scanf_s("%d%c", &a[i][j], &check, 1) != 2 || check != '\n')
			{
				printf("Введенное значение неверно. Введите целое число\n");
				while (getchar() != '\n');
			}
		}
	}
}
*\endcode
*/

void manualEnter(int* a[], int n, char check)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Введите элемент [%d][%d]: ", i + 1, j + 1);
			while (scanf_s("%d%c", &a[i][j], &check, 1) != 2 || check != '\n')
			{
				printf("Введенное значение неверно. Введите целое число\n");
				while (getchar() != '\n');
			}
		}
	}
}

/*!
\brief Функция автоматического ввода значений матрицы
\param[in] a Динамический массив
\param[in] n Размер массива
*\code
void randomEnter(int* a[], int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = -50 + rand() % 100;
		}
	}
}
*\endcode
*/


void randomEnter(int* a[], int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = -50 + rand() % 100;
		}
	}
}

/*!
\brief Функция создания массива
\param[in] a Динамический массив
\param[in] n Размер массива
*\code
void createArray(int* a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
}
*\endcode
*/


void createArray(int* a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
}

/*!
\brief Точка входа в программу
*/

int main()
{
	setlocale(LC_ALL, "Rus");
	int size = 0;
	bool symmetry = true;
	char check = '\0';
	int menuChoice;
	int enterCheck;
	bool hasMatrix = false;
	int** array = NULL;


	while (true)
	{

		printf("Выберите, что Вы хотите сделать\n 1. Ввод значений массива\n 2. Обработка массива\n 3. Вывод массива на экран\n 4. Выход из программы\n");
		while (scanf_s("%d%c", &menuChoice, &check, 1) != 2 || check != '\n' || menuChoice > 4 || menuChoice < 1)
		{
			printf("Введенное значение неверно. Выберите действие от 1 до 4: ");
			while (getchar() != '\n');
		}

		if (menuChoice == 1) 
		{
			//Ввод значений массива
			deleteArray(array, size);

			printf("Введите размер матрицы n x n\n");
			while (scanf_s("%d%c", &size, &check, 1) != 2 || check != '\n' || size < 0)
			{
				printf("Введенное значение неверно. Введите положительное целое число\n");
				while (getchar() != '\n');
			}
			
			array = new int*[size];
			createArray(array, size);

			printf("Как вы хотите заполнить массив?\n 1. Заполнить вручную\n 2.Заполнить случайными значениями\n");
			while (scanf_s("%d%c", &enterCheck, &check, 1) != 2 || check != '\n' || enterCheck > 2 || enterCheck < 1)
			{
				printf("Введенное значение неверно. Выберите действие 1 или 2: ");
				while (getchar() != '\n');
			}

			if (enterCheck == 1)
			{
				manualEnter(array, size, check);
			}

			if (enterCheck == 2)
			{
				randomEnter(array, size);
			}
			hasMatrix = true;
		}

		if (menuChoice == 2)
		{
			//Обработка массива
			if (hasMatrix == true) 
			{
				processingArray(array, size, symmetry);
			}
			else printf("Матрица не заполнена!\n");
		}

		if (menuChoice == 3)
		{
			//Вывод массива
			if (hasMatrix == true)
			{
				drawArray(array, size);
			}
			else printf("Матрица не заполнена!\n");
		}

		if (menuChoice == 4)
		{
			//Выход из программы
			deleteArray(array, size);
			return 0;
		}
	}

	getchar();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"