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


void _mergesort(int *array, size_t lb, size_t ub, size_t size)
{
	size_t mid;

	if (lb < ub)
	{
		mid = (lb + ub)/2;
		_mergesort(array, lb, mid, size);
		_mergesort(array, mid + 1, ub, size);
		printf("Merging...\n");
		prints(array, "left", lb, mid);
		prints(array, "right", mid, ub);
		_merge(array, lb, mid, ub, size);
	}

}


/**
 * _merge - merge the sub arrays
 * @array: array
 * @lb: lower bound of array
 * @ub: upper bound of array
 * @mid: mid point of array
 *
 * Return: void
 */
void _merge(int *array, size_t lb, size_t mid, size_t ub, size_t size)
{
	size_t i, j, k;
	int *sorted;

	i = lb;
	j = mid + 1;
	k = lb;

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
	prints(sorted, "Done", lb, ub);
	for (k = lb; k <= ub; k++)
		array[k] = sorted[k];
	free(sorted);
}


void prints(int *array, char *side, size_t lb, size_t ub)
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
