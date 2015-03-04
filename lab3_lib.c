/** lab3_lib.c: implements sorting and searching functions.
*
*
* Name: Ben Gregory
* Email: bgregor@purdue.edu
* Course: CNIT 315
* Lab batch: 10
* Lab assignment: 3
* Date: 2/15/2015
*
* Collaborators: None
*
*/

#include <stdio.h>
#include <string.h> //for memcpy

#include "lab3_lib.h"

/*
 * Pro-tip: use this function to copy arrays.
 */
void deep_copy_array(int* array_from, int* array_to, int array_length){
	//Read more about memcpy over here: http://www.cplusplus.com/reference/
	//cstring/memcpy/
	memcpy(array_from, array_to, array_length*sizeof(int));
}

/*
 * Pro-tip:use this function to generate random arrays.
 */
int generate_random_int_array(int* array, int array_length){
	/* Initialize */
	int i;
	/* Validate input */
	if(!array){
		printf("Error: Input array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: required array size < 1\n");
		return 1;
	}
	/* Generate random values */
	for (i = 0; i < array_length; i++) {
		array[i] = rand();
	}
	return 0;
}


int bubble_sort(int* array_unsorted, int array_length, int* array_sorted){
	/* Initialize */

	//Variable declarations
    int i, j, k, swap, h;

	/* Validate input */
	if(!array_unsorted){
		printf("Error: Unsorted array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: unsorted array size < 1\n");
		return 1;
	}
	if(array_sorted == NULL){
		printf("Error: sorted array is NULL\n");
		return 1;
	}
	/* Sort array */
    deep_copy_array(array_sorted, array_unsorted, array_length);
	for (i = 0; i < (array_length - 1); i++)
    {
        for (j = 0; j < (array_length - i - 1); j++)
        {
            if (array_sorted[j] > array_sorted[j + 1])
            {
                swap = array_sorted[j];
                array_sorted[j] = array_sorted[j + 1];
                array_sorted[j + 1] = swap;
            }
        }
    }

	return 0;
}


int selection_sort(int* array_unsorted, int array_length, int* array_sorted){
	/* Initialize */
    int i, j, k, pos, swap, h;
	//Put your variable declarations here.

	/* Validate input */
	if(!array_unsorted){
		printf("Error: Unsorted array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: unsorted array size < 1\n");
		return 1;
	}
	if(array_sorted == NULL){
		printf("Error: sorted array is NULL\n");
		return 1;
	}
	/* Sort array */
    deep_copy_array(array_sorted, array_unsorted, array_length);
    for (i = 0; i < array_length; i++)
    {
        pos = i;

        for (j = (i + 1); j < array_length; j++)
        {
            if (array_sorted[pos] > array_sorted[j])
            {
                pos = j;
            }
        }

        if (pos != i)
        {
            swap = array_sorted[i];
            array_sorted[i] = array_sorted[pos];
            array_sorted[pos] = swap;
        }
    }
    
	return 0;
}

int insertion_sort(int* array_unsorted, int array_length, int* array_sorted){
	/* Initialize */

    int i, j, k, h;    

	/* Validate input */
	if(!array_unsorted){
		printf("Error: Unsorted array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: unsorted array size < 1\n");
		return 1;
	}
	if(array_sorted == NULL){
		printf("Error: sorted array is NULL\n");
		return 1;
	}
	/* Sort array */
    deep_copy_array(array_sorted, array_unsorted, array_length);
    for (i = 1; i <= (array_length - 1); i++)
    {
        j = i;

        while (j > 0 && array_sorted[j] < array_sorted[j - 1])
        {
            k = array_sorted[j];
            array_sorted[j] = array_sorted[j - 1];
            array_sorted[j - 1] = k;

            j--;
        }
    }

	return 0;
}

int linear_search(int* array, int array_length, int value, int* location){
	/* Initialize */

	int i;

	/* Validate input */
	if(!array){
		printf("Error: array pointer is NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: array size < 1\n");
		return 1;
	}
	if(!location){
		printf("Error: location variable is NULL\n");
		return 1;
	}
	/* Search array */
  
    for (i = 0; i < array_length; i++)
    {
        if (array[i] == value)
        {
            *location = i;
            break;
        }
        
        if (i == array_length)
        {
        printf("%d not found\n", value);
        *location = -1;
        return 1;
        }
    }	
    
    
    
	return 0;
}

/*
 * You will have to implement this entire function! Remember to check for
 * input errors like the other functions.
 */
int binary_search(int* array, int array_length, int value, int* location){
    
    /* Initialize */

    int i, j, k, h = 0;    

	/* Validate input */
	if(!array){
		printf("Error: Unsorted array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: unsorted array size < 1\n");
		return 1;
	}
    if(!location){
		printf("Error: location variable is NULL\n");
		return 1;
	}
	/* Sort array */

    i = 0;
    j = array_length - 1;
    k = (i + j) / 2;

    while (i <= j)
    {
        if (array[k] < value)
        {
            i = k + 1;
        }
        
        else if (array[k] == value)
        {
            *location = k;
            h = 1;
            break;
        }
        
        else if (i > j)
        {
          *location = -1;
          return 1;
        }
        
        else
        {
            j = k - 1;
        }

        k = (i + j) / 2;
    }    
    
    if (h == 0)
    {
      *location = -1;
      return 1;
    }
    
	return 0;
}
