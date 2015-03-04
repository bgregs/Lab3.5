/** lab3_5_main.c: Implements a front end for lab3_lib.c.
*
*
* Name: Ben Gregory
* Email: bgregor@purdue.edu
* Course: CNIT 315
* Lab batch: 10
* Lab assignment: 3.5
* Date: 3/2/2015
*
* Collaborators: None
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "lab3_lib.h"

/**
 * Accepts user defined inputs for an array of an undefined length and calls
 * functions from lab3_lib.h to sort/search for values.
 *
 * 	@return 	0 - Successful completion of the program.
 * 				1 - An error during execution.
 */
int main(){
	/* Initialize */

	char yesNo = 'y';
  int menuChoice, i = 0, value;
  int *array, *tempMem;
  array = malloc(sizeof(int)); //allocate memory for array
  
	/* Menu */
	
	while (yesNo == 'y')
	{
	  menuChoice = 0;
    printf("\nPlease select Add new value (1), Sort Array (2), "
    "or Search for value (3): ");
    scanf("%d", &menuChoice);
    
    if (menuChoice == 1)
    {
      yesNo == 'y';
      printf("\nEnter integer: ");
      scanf("%d", &value);
      
      array[i] = value;
      tempMem = realloc(array, (i + 2)*sizeof(int)); //dynamically increase size
      if (tempMem != NULL)
      {
        array = tempMem;
      }
      
      else
      {
        free(array);
        return 1;
      }
      
      i++;
    }          
  
    else if (menuChoice == 2)
    {
      int sortedArray[i], index; 
      
      selection_sort(array, i, sortedArray);
      for (index = 0; index < i; index++)
      {
        printf("\n%d", sortedArray[index]);
      }
    }
  
    else if (menuChoice == 3)
    {
      int searchValue, sortedArraySearch[i], location = 0;
      
      printf("\nSearch Value: ");
      scanf("%d", &searchValue);
      
      selection_sort(array, i, sortedArraySearch);
      binary_search(sortedArraySearch, i, searchValue, &location);
      
      if (location != -1)
      {
        printf("\nSearch value was found at index %d", location);
      }
      
      else
      {
        printf("\nSearch value was not found");
      }
    }
       
    else
    {
      printf("Please enter a value that corresponds to the numbers 1 - 5\n");
      break;
    }
  }
	/* Wrap up */

	return 0;
} //End int main()
