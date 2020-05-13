/**e
 *   ************************************************************************************
 *   * Given an array of integers, return indices of the two numbers such that they add *
 *   * Up to a specific target.                                                         *
 *   *                                                                                  *
 *   * You may assume that each input would hace exactly one solution, and you          *
 *   * may not use the same element twice.                                              *
 *   *                                                                                  *
 *   ************************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

// Prototype Function

int *ConvertStringToAnArrayOfNumbers(char ArrayOfNumber[]);
void GetTheSum(int* PunteroOfNumber);
unsigned char CheckArrayLength(char ArrayOfNumber[]);

// Extern Variable

unsigned char Check;

int main(void)
{
	extern unsigned char Check;

	char ArrayOfNumber[] = {'1','2','3','4','4','5','3','2','5','\0'};
	int SolveNumber, NumberOfColumns, i;
	int *PunteroOfNumber;

	Check = CheckArrayLength(ArrayOfNumber);

	if (Check)
	{
		PunteroOfNumber = ConvertStringToAnArrayOfNumbers(ArrayOfNumber);
		GetTheSum(PunteroOfNumber);
	}
	else
	{
		printf("El array fue demasiado pequeño");
		return (-1);
	}
}

unsigned char CheckArrayLength(char ArrayOfNumber[])
{
	int i;

	i = 0;
	while (*ArrayOfNumber)
		i++, ArrayOfNumber++;

	return ((unsigned char) i);
}

int *ConvertStringToAnArrayOfNumbers(char ArrayOfNumber[])
{

	int *Number = (int *)malloc(Check*(sizeof(int)));

	int i = 0;
	while (*ArrayOfNumber)
	{
		Number[i] = *ArrayOfNumber - '0';
	        ArrayOfNumber++, i++;
	}

	return (Number);
}
void GetTheSum(int* PunteroOfNumber)
{
	extern unsigned char Check;
	int SolverNumber, NumberOfColum, Index;
	int target = -1;

	NumberOfColum = Index = 0;
	while (Index < (Check))
	{
		if (Index == 0)
		{
			SolverNumber = *(PunteroOfNumber + NumberOfColum);
		}

		if (!(Index == NumberOfColum) && ((*(PunteroOfNumber)+ SolverNumber) == target))
		{
			printf("Se encontro el target:\n[%d, %d]\n", NumberOfColum, Index);
			exit(0);
		}
		else
			Index++, PunteroOfNumber++;

		if (NumberOfColum == (Check - 1) && (Index == (Check - 1)))
			Index = Check;
		else if (Index == (Check - 1))
		        PunteroOfNumber -= Index, Index = 0, NumberOfColum++;
	}
	printf("no se encontro el target\n");
	exit (-1);

}
