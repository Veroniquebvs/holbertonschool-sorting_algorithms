#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @a: first node
 * @b: second node (the one after a)
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (!a || !b)
		return;

	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - sorts a doubly linked list of
 * ints using insertion sort
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		tmp = current;

		while (tmp->prev && tmp->prev->n > tmp->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			print_list(*list);
		}

		current = current->next;
	}
}
