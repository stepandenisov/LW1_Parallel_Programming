#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void get_matrix(FILE* fp, const size_t size)
{
	srand(time(NULL));
	double** m = new double*[size];
	for (size_t i = 0; i < size; i++)
	{
		m[i] = new double[size];
		for (size_t j = 0; j < size; j++)
		{
			m[i][j] = rand();
		}
	}
	fprintf(fp, "%u ", size);
	fprintf(fp, "\n");
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			fprintf(fp, "%lf ", m[i][j]);
		}
		fprintf(fp, "\n");
	}
	delete[] m;
}

void write_matrix(FILE* fp, double**& matrix, size_t size)
{
	fprintf(fp, "%u ", size);
	fprintf(fp, "\n");
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			fprintf(fp, "%lf ", matrix[i][j]);
		}
		fprintf(fp, "\n");
	}
}

void read_matrix(FILE* fp, double**& matrix)
{
	size_t size;
	fscanf(fp, "%u ", &size);
	cout << size << endl;
	matrix = new double*[size];
	for (size_t i = 0; i < size; i++)
	{
		matrix[i] = new double[size];
		for (size_t j = 0; j < size; j++)
		{
			fscanf(fp, "%lf ", &matrix[i][j]);
		}
	}
}

void mul_matrix(double**& matrix1, double**& matrix2, double**& matrixres, size_t size)
{
	matrixres = new double*[size];
	for (size_t i = 0; i < size; i++)
	{
		matrixres[i] = new double[size];
		for (size_t j = 0; j < size; j++)
		{
			matrixres[i][j] = 0;
			for (size_t k = 0; k < size; k++)
				matrixres[i][j] += matrix1[i][k] * matrix2[k][j];
		}
	}
}

void print_matrix(double**& matrix, size_t size)
{
	cout << endl;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	clock_t start = clock();
	FILE *m1, *m2, *mres;
	size_t size = 100;
	double** matrix1 = NULL, **matrix2 = NULL, **matrixres = NULL;

	cout << "Open : ";

	// Открытие файла
	m1 = fopen("matrix1.txt", "w");
	m2 = fopen("matrix2.txt", "w");
	get_matrix(m1, size);
	get_matrix(m2, size);
	// Создание матриц
	freopen("matrix1.txt", "r", m1);
	freopen("matrix2.txt", "r", m2);
	read_matrix(m1, matrix1);
	read_matrix(m2, matrix2);
	// Закрытие файла
	fclose(m1);
	fclose(m2);
	// Умножение матриц
	mul_matrix(matrix1, matrix2, matrixres, size);
	mres = fopen("mres.txt", "w");
	write_matrix(mres, matrixres, size);
	printf("\nClose\n");
	clock_t end = clock();
	cout << "Tine of mul:" << (double)(end - start) / CLOCKS_PER_SEC << endl;
	return 0;
}