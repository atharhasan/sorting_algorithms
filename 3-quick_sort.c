#include "sort.h"


/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with the Lomuto partition scheme.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_rec(array, 0, size - 1, size);
}

/**
 * quicksort_rec - Recursively sorts a partition of an array
 * using the Quick sort algorithm with the Lomuto partition scheme.
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quicksort_rec(int *array, int low, int high, size_t size)
{
	int par_idx;

	if (low < high)
	{
		par_idx = lomuto_par(array, low, high, size);

		quicksort_rec(array, low, par_idx - 1, size);
		quicksort_rec(array, par_idx + 1, high, size);
	}
}

/**
 * lomuto_par - Partitions the array using the Lomuto scheme
 * for the Quick sort algorithm and returns the pivot index.
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: The index of the pivot after partitioning
 */
int lomuto_par(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;

			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	print_array(array, size);

	return (i + 1);
}
