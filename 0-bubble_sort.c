#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, flag;

	if (size < 2)
		return;

	else
	{
		for (i = 0; i < size - 1; i++)
		{
			flag = 0;
			for (j = 0; j < size - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					flag = 1;
					print_array(array, size);
				}
			}
			if (flag == 0)
				break;
		}
	}
}
