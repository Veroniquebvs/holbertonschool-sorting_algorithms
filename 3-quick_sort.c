#include "sort.h"

/**
 * swap_int - swaps two integers in an array
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap_int(int *a, int *b)
{
	int tmp;

	if (a == b)
		return;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - partitions an array using Lomuto scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index
 * @size: size of the array (for printing)
 *
 * Return: index of the pivot after partition
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap_int(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swap_int(&array[i], &array[high]);
	if (i != high)
		print_array(array, size);

	return i;
}

/**
 * quick_sort_recursive - recursive Quick sort helper
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array (for printing)
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		if (pivot_index > 0)
			quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme)
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
