#include "sort.h"

/**
 * lomuto_partition - Implements the Lomuto partition for Quick sort.
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the entire array.
 *
 * Return: The final index of the pivot element.
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i, j;

	for (i = low - 1, j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				/* Swap elements */
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		/* Swap pivot to its final position */
		int temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts a subarray using Quick sort (patent pending)
 * @array: The array to be sorted.
 * @low: The starting index of the subarray.
 * @high: The ending index of the subarray.
 * @size: The size of the entire array.
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		/* Partition the array and get the pivot index */
		ssize_t pivot_idx = lomuto_partition(array, low, high, size);

		/* Recursively sort elements before and after the pivot */
		quick_sort_recursive(array, low, pivot_idx - 1, size);
		quick_sort_recursive(array, pivot_idx + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
