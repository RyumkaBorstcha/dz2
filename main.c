#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include "functions.h"
#include "bignum.h"

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)


void e1()
{
	int s=0;
	for (int i = 1; i < 1000; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0) s += i;
	}
	printf("e1: %d\n", s);
}

void e2()
{
	int a = 1;
	int b = 0;
	int c = 0;
	int s = 0;
		while (c <= 4000000)
		{ 
			c = a + b;
			if (c % 2 == 0)
			{
				s += c;
				printf("%d \n", c);
			}
			a = b;
			b = c;
			
		}
	printf("e2: %d\n", s);
}

void e3()
{
	long long num = 600851475143;
	long long count = 1;
		while (num != 1)
		{
			count += 1;
				if (num% count == 0) num /= count;
		}
	
	printf("e3: %d\n", count);
}
	
void e4()
{
	const int max = 999;
	const int min = 99;
	int maxProduct = 0;
		for (int i = max; i > min; i--)
		{
			for (int j = max; j > min; j--)
			{
				int product = i * j;
				if (is_palindrome(product) == 1)
				{
					if (maxProduct < product) {
						maxProduct = product;
					}
					break;
				}
			}
		}
	
	printf("e4: %d\n", maxProduct);
}

void e5()
{
	int flag = 1;
	int i = 1;
	while (flag)
		for (int j = 1; j < 21; j++)
		{
			if (i % j != 0)
			{
				i++;
				break;
			}
			else if (i % j == 0 && j == 20)
				flag = 0;
		}
	printf("e5: %d\n", i);
}

void e6()
{
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 1; i <= 100; ++i) 
	{
		sum1 += i * i;
		sum2 += i;
	}
	printf("e6: %d\n", sum2 * sum2 - sum1);
}

void e7()
{
	int count = 0;
	int ans = 0;

	for (; count < 10001; ans++)
	{
		if (IsPrime(ans) == 1)
			count++;
	}

	printf("e7: %d\n", ans - 1);
}

void e8()
{
	unsigned long long ans = 0;
	char num[1000] = { "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450" };

	for (int i = 0; i < 987; i++)
	{
		unsigned long long curans = 0;
		curans = ((int)(num[i] - '0')) * ((int)(num[i + 1] - '0'));
		curans = curans * ((int)(num[i + 2] - '0')) * ((int)(num[i + 3] - '0'));
		curans = curans * ((int)(num[i + 4] - '0')) * ((int)(num[i + 5] - '0'));
		curans = curans * ((int)(num[i + 6] - '0')) * ((int)(num[i + 7] - '0'));
		curans = curans * ((int)(num[i + 8] - '0')) * ((int)(num[i + 9] - '0'));
		curans = curans * ((int)(num[i + 10] - '0')) * ((int)(num[i + 11] - '0')) * ((int)(num[i + 12] - '0'));
		ans = max(curans, ans);
	}

	printf("e8: %llu\n", ans);
}

void e9()
{
	for (int i = 1; i <= 995; i++)
		for (int j = i + 1; j <= 996; j++)
			for (int k = j + 1; k <= 997; k++)
				if ((i * i + j * j == k * k) && (i + j + k == 1000))
					printf("e9: %d\n", i * j * k);
}

void e10()
{
	long long sum = 0;

	for (int i = 2; i < 2000000; i++)
		if (IsPrime(i) == 1)
			sum += i;

	printf("e10: %lli\n", sum);
}

void e11()
{
	int m[20][20] = { 8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8,
		 49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0,
		 81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65,
		 52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91,
		 22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80,
		 24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50,
		 32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70,
		 67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21,
		 24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,
		 21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95,
		 78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92,
		 16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57,
		 86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58,
		 19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40,
		 4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66,
		 88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69,
		 4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36,
		 20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16,
		 20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54,
				 1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48 };

	int ans = 0;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			int column = 0;
			int string = 0;
			int uptodown = 0;
			int	downtoup = 0;
			if (j < 17)
			{
				string = m[i][j] * m[i][j + 1] * m[i][j + 2] * m[i][j + 3];
			}
			if (i < 17)
			{
				column = m[i][j] * m[i + 1][j] * m[i + 2][j] * m[i + 3][j];
			}
			if ((i < 17) && (j < 17))
			{
				downtoup = m[i][j] * m[i + 1][j + 1] * m[i + 2][j + 2] * m[i + 3][j + 3];
			}
			if ((i > 3) && (i < 17) && (j > 3))
			{
				uptodown = m[i][j] * m[i + 1][j - 1] * m[i + 2][j - 2] * m[i + 3][j - 3];
			}
			ans = max(ans, max(string, max(column, max(downtoup, uptodown))));
		}
	}

	printf("e11: %d\n", ans);
}

void e12()
{
	unsigned int tree = 0;
	int count = 1;
	int lim;

	for (int i = 1; count <= 500; i++)
	{
		count = 1;
		tree += i;
		lim = sqrt(tree);
		for (int j = 2; j <= lim; j++)
			if (tree % j == 0)
				if (j == lim)
					count++;
				else
					count += 2;
	}

	printf("e12: %d\n", tree);
}

void e13()
{
	FILE* F;
	F = fopen("text.txt", "r");
	if (!F)
		return;

	char num[51] = "";
	struct bn* x = MemConstruct("0");
	struct bn* y = NULL;

	for (int i = 0; i < 100; i++)
	{
		fscanf_s(F, "%s", num, 51);
		y = MemConstruct(num);
		x = Sumofbn(x, y);
	}

	printf("e13: ");
	Printbn(x);
	printf("\n");
}

void e14()
{
	long long n = 0;
	long long count = 0;
	long long max = 0;
	int N = 0;
	for (int i = 1000000; i > 1; --i)
	{
		n = i;
		count = 1;
		while (n > 1)
		{
			if (n % 2 == 0)
			{
				n /= 2;
				++count;
			}
			else
			{
				n = (n * 3) + 1;
				++count;
			}
		}
		if (count >= max)
		{
			max = count;
			N = i;
		}
	}
	printf("e14: %d\n", N);
}

void e15()
{
	long long int arr[21][21] = { 0 };
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
		{
			if (i == 0 && j == 0)
				arr[i][j] = 0;
			else
				if (i == 0 || j == 0)
					arr[i][j] = 1;
				else
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	printf("e15: %lli\n", arr[20][20]);
}


int main()
{
	//e1(); //233168
	//e2(); //4613732
	//e3(); //6857
	//e4(); //906609
	//e5(); //232792560
	//e6(); //25164150
	//e7(); //104743
	//e8(); //23514624000
	//e9(); //31875000
	//e10(); //142913828922
	//e11(); //70600674
	//e12(); //76576500
	//e13(); 
	//e14(); //837799
	//e15(); // 137846528820
	

	//String();

	FILE* f;
	fopen_s(&f, "DatesIn.txt", "r");

	if (!f)
		return 0;
	DatesFunc(f);

	return 0;
}