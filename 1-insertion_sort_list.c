#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * using the insertion sort algorithm
 * @list: pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nextnode, *temp, *backnode;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	temp = (*list)->next;
	nextnode = temp->next;
	while (temp)
	{
		if (temp->n < temp->prev->n)
		{
			backnode = temp->prev;
			while (backnode && (temp->n < backnode->n))
			{
				if (backnode->prev == NULL)
				{
					backnode->next = temp->next;
					if (temp->next != NULL)
						temp->next->prev = temp->prev;
					temp->prev = NULL;
					temp->next = backnode;
					(*list) = backnode->prev = temp;
				}
				else
				{
					backnode->next = temp->next;
					if (temp->next != NULL)
						temp->next->prev = temp->prev;
					temp->prev = backnode->prev;
					temp->next = backnode;
					backnode->prev->next = temp;
					backnode->prev = temp;
				}
				print_list(*list);
				backnode = temp->prev;
			}
		}
		temp = nextnode;
		if (temp)
			nextnode = nextnode->next;
	}
}
