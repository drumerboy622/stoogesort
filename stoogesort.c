/***************************************************************************************
 * AUTHOR: MATTHEW sOLBRACK
 * Date: 04/13/2019
 * subject: stoogeSort will take values from data.txt and arrange them using 
 * the stooge sort functionality.
 * ***********************************************************************************/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void stoogeSort(int left, int right, int arr[])
{

	//assert the left isn't greater or equal to the right
	if (left >= right)
		return; 

	//if n = 2 check index left and right and swap if needed
	if (right-left+1 == 2 && arr[left] > arr[right])
	{
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}

	//if n > 2 execute the recursive calls of stoogesort
	else if (right-left+1>2)
	{
		int m = (right-left+1)/3;
		stoogeSort(left, right-m, arr);
		stoogeSort(left+m, right, arr);
		stoogeSort(left, right-m, arr);
	}
}

int main()
{
	int temp, i=0, j=0, k, pos=0;
	int * arr;
	int * arrTemp;
	arr = malloc(100 * sizeof(int));
	arrTemp = malloc(100 * sizeof(int));
	FILE * textFile;
	FILE * stoogeFile;

	if((textFile = fopen("data.txt", "r")))
	{
		while((fscanf(textFile, "%d", &arr[i])) != EOF)
		{	
			++i;
		}
		fclose(textFile);
	}

	stoogeFile = fopen("stooge.out", "w");

	if(!stoogeFile)
	{
		printf("StoogeFile Failed to Open");
		exit(-1);
	}
	
	while(j < i)
	{
		pos = arr[j];
		j++;
		for(k=0; k < pos; k++)
		{

			arrTemp[k] = arr[j];
			j++;
		}

		stoogeSort(0, k-1, arrTemp);
		
		for(temp=0; temp < k; temp++)
		{
			fprintf(stoogeFile, "%d ", arrTemp[temp]);
		}
		fprintf(stoogeFile, "\n");
	}

	free(arr);
	free(arrTemp);
	fclose(stoogeFile);

	return 0;
}	 

 	
