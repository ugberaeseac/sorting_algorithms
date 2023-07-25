#include "sort.h"

/**
 * merge_sort - sort an array of integers using the Merge sort algorithm
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t lb;
	size_t ub;

	lb = 0;
	ub = size - 1;

	if (array == NULL || size < 2)
		return;

	_mergesort(array, lb, ub, size);

}

/**
 * _mergesort - recursively divide array
 * @array: array to sort
 * @lb: lower bound array
 * @ub: upper bound array
 * @size: size of array
 *
 * Return: void
 */
void _mergesort(int *array, size_t lb, size_t ub, size_t size)
{
	size_t mid;

	if (lb < ub)
	{
		mid = (lb + ub) / 2;
		_mergesort(array, lb, mid, size);
		_mergesort(array, mid + 1, ub, size);
		printf("Merging...\n");
		_print(array, "left", lb, mid);
		_print(array, "right", mid, ub);
		_merge(array, lb, mid, ub, size);
	}

}


/**
 * _merge - merge the sub arrays
 * @array: array
 * @lb: lower bound of array
 * @ub: upper bound of array
 * @mid: mid point of array
 * @size: size of array
 *
 * Return: void
 */
void _merge(int *array, size_t lb, size_t mid, size_t ub, size_t size)
{
	size_t i, j, k;
	int *sorted;

	i = k = lb;
	j = mid + 1;
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	while (i <= mid && j <= ub)
	{
		if (array[i] <= array[j])
		{
			sorted[k] = array[i];
			i++;
		}
		else
		{
			sorted[k] = array[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= ub)
		{
			sorted[k] = array[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			sorted[k] = array[i];
			i++;
			k++;
		}
	}
	_print(sorted, "Done", lb, ub);
	_arraycpy(array, sorted, k, ub);
}

/**
 * _arraycpy - copy the sorted array
 * @array: original array of integers
 * @sorted: sorted array
 * @k: lower bound of array
 * @ub: upper bound of array
 *
 * Return: void
 */
void _arraycpy(int *array, int *sorted, size_t k, size_t ub)
{
	for (k = 0; k <= ub; k++)
		array[k] = sorted[k];
}


/**
 * _print - print elements of merged sub arrays
 * @array: array
 * @side: two sides of the array
 * @lb: lower bound of array
 * @ub: upper bound of array
 *
 * Return: void
 */
void _print(int *array, char *side, size_t lb, size_t ub)
{
	size_t i;

	printf("[%s]: ", side);
	for (i = lb; i < ub; i++)
	{
		if (i != (ub - 1))
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}

}
