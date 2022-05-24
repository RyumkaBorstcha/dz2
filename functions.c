#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "functions.h"
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)

int is_palindrome(int number)
{
	int value = number;
	int reversed = 0;
	while (value > 0)
	{
		reversed *= 10;
		reversed += value % 10;
		value /= 10;
	}
	if (reversed == number) {
		return 1;
	}
	else {
		return 0;
	}

}

int IsPrime(long long number) //Простое
{
	if (number <= 1)
		return 0;
	int i = 0;
	int r = 0;
	int prime = 1;
	if (number != 2 && number % 2 == 0)
		prime = 0;
	else
		for (i = 3, r = sqrt(number); i <= r && prime; i += 2)
			if (number % i == 0)
				prime = 0;

	return prime;
}

void String() //Скобки
{
	FILE* F = fopen("str.txt", "r");
	if (!F)
		return;

	char sym = '0';
	int count = 0;
	int save = 0;

	for (int i = 0; sym != EOF; i++)
	{
		sym = getc(F);

		if (sym == '(')
			count++;
		else if (sym == ')')
		{
			count--;
			if (count == -1)
				save = i;
		}
	}

	printf("String: ");
	if (count == 0)
		printf("0");
	if (count > 0)
		printf("-1");
	if (count < 0)
		printf("%d", save);

	printf("\n");
}

int DatesToStruct(FILE* f, struct Date* dates_)
{
	char str[16] = "";
	int i = 0;
	int n = 0;
	for (; fgets(str, 16, f); i++)
	{
		n++;
		dates_[i].day = 10 * (str[0] - 48) + (str[1] - 48);
		dates_[i].month = 10 * (str[3] - 48) + (str[4] - 48);
		dates_[i].year = 1000 * (str[6] - 48) + 100 * (str[7] - 48) + 10 * (str[8] - 48) + (str[9] - 48);
	}
	return n;
}

int CompDates(struct Date date1_, struct Date date2_)
{
	if (date1_.year > date2_.year)
		return 1;

	if (date1_.year < date2_.year)
		return -1;

	if (date1_.year == date2_.year)
	{
		if (date1_.month > date2_.month)
			return 1;

		if (date1_.month < date2_.month)
			return -1;

		if (date1_.month == date2_.month)
		{
			if (date1_.day > date2_.day)
				return 1;

			if (date1_.day < date2_.day)
				return -1;

			if (date1_.day == date2_.day)
				return 0;
		}
	}
}

void DatesSort(struct Date* dates_, int count_)
{
	struct Date temp;
	for (int i = 0; i < count_ - 1; i++)
		for (int j = count_ - 1; j > i; j--)
			if (CompDates(dates_[j - 1], dates_[j]) == -1)
			{
				temp = dates_[j];
				dates_[j] = dates_[j - 1];
				dates_[j - 1] = temp;
			}
}

void DatesFunc(FILE* f)
{
	FILE* g;

	fopen_s(&g, "DatesOut.txt", "w");
	if (!g)
		return 0;

	struct Date* dates = malloc(sizeof(struct Date) * 1024);
	if (!dates)
		return 0;

	int n = DatesToStruct(f, dates);

	DatesSort(dates, n);

	for (int i = 0; i < n; i++)
		fprintf(g, "%.2d/%.2d/%.4d\n", dates[i].day, dates[i].month, dates[i].year);
}