#include "sort.h"

/*
 * quick_sort - sorts an array of integers using the
 * quick sort algorithm
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_quicksort(array, 0, size - 1, size);

}


/*
 * _partition_array - partitions the array into sub-arrays
 * @array: array to partition
 * @low: lower bound of array
 * @high: higher bound of array
 * @size: size of array
 *
 * Return: sorted index f pivot
 */
int _partition_array(int *array, int low, int high, size_t size)
{
	int i, j, temp;
	int pivot;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j]  <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		temp = array[high];
		array[high] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
	return (i);
}

/*
 * _quicksort - partitions and sorts the array
 * @array: array to sort
 * @low: lower bound of array
 * @high: upper bound of array
 * @size: size of array
 *
 * Return: void
 */
void _quicksort(int *array, int low, int high, size_t size)
{
	int pivotIndex;

        if (low < high)
        {
                pivotIndex = _partition_array(array, low, high, size);
                _quicksort(array, low, pivotIndex - 1, size);
		_quicksort(array, pivotIndex + 1, high, size);
        }

}
