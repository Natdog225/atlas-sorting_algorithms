#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm with Knuth sequence.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate the largest gap in the sequence that is less than size */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Start with the largest gap and work down to 1 */
	while (gap > 0)
	{
		/* Perform insertion sort for elements at the current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			/* Shift elements greater than temp forward */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3; /* Move to the next smaller gap */
	}
}