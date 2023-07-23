#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t temp, minIndex;

	if (size < 2)
		return;

	else
	{
		for (i = 0; i < size - 1; i++)
		{
			minIndex = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[minIndex])
					minIndex = j;
			}
			if (minIndex != i)
			{
				temp = array[i];
				array[i] = array[minIndex];
				array[minIndex] = temp;
				print_array(array, size);
			}
		}
	}
}
