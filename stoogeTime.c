/*********************************************************************
 * Author: Matthew Solbrack
 * Date: 04.13.2019
 * Subject: executing the stooge sort algorithm 10 times and printing
 * the time it takes to execute.
 * *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
int main() {
        int c, i=0, n, num[] = {5000, 500, 2500, 720, 3200, 1000, 750, 4500, 900, 4000};
        int arr[5000];
        double time_taken;
        clock_t algTime;

        // loop 10 times for all 10 numbers
        while(i < 10)
        {
                //randomly pick numbers for the array
                for (c = 0; c < num[i]; c++)
                {
                        n = rand() % 10000;
                        arr[c] = n;
                }

                //record the clock time
                algTime = clock();
                //call to function to sort
                stoogeSort(0, c-1, arr);
                //end the clock time
                algTime = clock() - algTime;
                //calculate the time in seconds
                time_taken = ((double)algTime)/CLOCKS_PER_SEC;

                printf("Size of array: %d | Time to execute(sec): %f \n", c, time_taken);

                i++;

        }
        return(0);
}

