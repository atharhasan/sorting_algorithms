#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: the list will be insertion
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *cur;

	if (!list || !*list || !(*list)->next)
		return;

	cur = (*list)->next;

	while (cur != NULL)
	{
		temp = cur->next;

		while (cur->prev != NULL && cur->n < cur->prev->n)
		{
			cur->prev->next = cur->next;
			if (cur->next != NULL)
				cur->next->prev = cur->prev;

			cur->next = cur->prev;
			cur->prev = cur->next->prev;

			if (cur->prev != NULL)
				cur->prev->next = cur;
			else
				*list = cur;

			cur->next->prev = cur;
			print_list(*list);
		}
		cur = temp;
	}
}
