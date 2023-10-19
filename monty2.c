#include "monty.h"
/**
 * add - adds the last two elements together
 * @stack: pointer to a doubly linked list
 * @line_num: the number of the line executed
 * Return: nothing
*/
void add(stack_t **stack, unsigned int line_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	aux->n += (*stack)->n;
	pop(stack, line_num);
}
