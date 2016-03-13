#ifndef __BUBBLE_H__
#define __BUBBLE_H__


void bubble_sort(int* array, int array_size);


/**
* swaps the element index in the given array with the next index
**/
void swap(int* array, int element_index);


/**
* swaps element pairs for the length of the array when the current element
* is greater than the next element.
**/
int swap_array(int* array, int array_size);


#endif
