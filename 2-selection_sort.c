#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */

void selection_sort(int *array, size_t size)
{
	size_t minIdx, i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		minIdx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIdx])
				minIdx = j;
		}
		if (i != minIdx)
		{
			temp = array[i];
			array[i] = array[minIdx];
			array[minIdx] = temp;
			print_array(array, size);
		}
	}
}
