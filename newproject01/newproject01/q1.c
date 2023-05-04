#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 8

isNumberInOrder(int[], int, int); /*Declaration of a function*/

int main1()
{
	int arr[N], number, i, flag = 1, counter = 0;

	while (flag)
	{
		printf("Enter %d integer numbers, please: ", N);

		for (i = 0; i < N && flag; i++)
			if (scanf("%d", &arr[i]) != 1)
				return 1;

		if (arr[0] == 0)
		{
			for (i = 0; i < N; i++)
			{
				if (arr[i] == 0)
					counter++;
			}
		}
		if (counter == N)
		{
			printf("Thank you, we need to finish");
			flag = 0;
			continue;
		}
		printf("Enter integer number, please: ");
		scanf("%d", &number);

		if (isNumberInOrder(arr, N, number))
			printf("The number %d is in the array \n", number);

		else
			printf("The number %d is not in the array \n", number);

		printf("\n");

	}
	return 0;
}

isNumberInOrder(int a[], int size, int number)
{
	int i, newnumber = 0;


	newnumber = number % 10;

	for (i = size - 1; i > 0; i--)
	{
		if (newnumber == a[i])
		{
			number = number / 10;
			newnumber = number % 10;
		}
	}
	if (number == 0)
		return 1;

	return 0;
}
