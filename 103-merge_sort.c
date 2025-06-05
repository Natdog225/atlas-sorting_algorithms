#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge_subarray(int *array, int *buffer, size_t left, size_t mid, size_t right);
void split_merge(int *array, int *buffer, size_t left, size_t right);

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm (top-down).
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	split_merge(array, buffer, 0, size);

	free(buffer);
}

/**
 * split_merge - Recursively splits the array and merges sorted subarrays.
 * @array: The array to be sorted.
 * @buffer: A temporary buffer for merging.
 * @left: The starting index of the subarray.
 * @right: The ending index (exclusive) of the subarray.
 */
void split_merge(int *array, int *buffer, size_t left, size_t right)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = (left + right) / 2;

	split_merge(array, buffer, left, mid);
	split_merge(array, buffer, mid, right);
	merge_subarray(array, buffer, left, mid, right);
}

/**
 * merge_subarray - Merges two sorted subarrays into a single sorted subarray.
 * @array: The original array.
 * @buffer: A temporary buffer to store the merged subarray.
 * @left: The starting index of the left subarray.
 * @mid: The starting index of the right subarray.
 * @right: The ending index (exclusive) of the right subarray.
 */
void merge_subarray(int *array, int *buffer, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	i = left;
	j = mid;
	k = left;

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}

	while (i < mid)
		buffer[k++] = array[i++];

	while (j < right)
		buffer[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}