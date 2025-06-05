#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_array = NULL;
	int *output_array = NULL;
	int max = 0;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Allocate memory for the counting array */
	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
		return;

	/* Initialize count_array to all zeros */
	for (i = 0; i <= (size_t)max; i++)
		count_array[i] = 0;

	/* Store the count of each element */
	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	/* Store the cumulative count */
	for (i = 1; i <= (size_t)max; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, max + 1);

	/* Allocate memory for the output array */
	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
		free(count_array);
		return;
	}

	/* Build the output */
	for (i = size - 1; (int)i >= 0; i--)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	free(count_array);
	free(output_array);
}