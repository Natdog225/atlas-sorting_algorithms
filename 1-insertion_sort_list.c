#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t
		*current,
		*insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
		{
			insert = current;
			current = current->next;

			while (insert->prev && insert->n < insert->prev->n)
			{
				temp = insert->prev;
				temp->next = insert->next;

				if (insert->next)
					insert->next->prev = temp;

				insert->prev = temp->prev;
				insert->next = temp;

				if (insert->prev)
					insert->prev->next = insert;
				else
					*list = insert;

				temp->prev = insert;

				print_list(*list);
			}
		}
}