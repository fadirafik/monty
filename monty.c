#include "monty.h"

/**
 * push - pushes an integer on top of a stack
 * @stack: pointer to the head of a stack
 * @num: number to be inserted
 * @line_num: number of the line
 * Return: nothing
*/
void push(stack_t **stack, int num, unsigned int line_num)
{
	stack_t *new_node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_num);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
/**
 * pall - function that prints the stack
 * @stack: pointer to the head of a stack
 * @line_num: number of the line
 * Return: nothing
*/
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *top = *stack;
	(void)line_num;

	if (!*stack)
	{
		return;
	}
	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

/**
 * pint - prints a stack in reverse
 * @stack: a stack pointer
 * @line_num: the number of the line to be executed
 * Return: nothing
*/
void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *top = *stack;
	(void)line_num;
	if (!*stack)
	{
		return;
	}
	printf("%d\n", top->n);
}

/**
 * pop - Removes the top element of the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}


	if (h)
	{
		*stack = (h)->next;
		free(h);
	}
}
/**
 * swap - Swaps the first two elements in a stack
 * @stack: pointer of stack
 * @line_num: line number
 * Return: Void
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack, *ptr;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (h && h->next)
	{
		ptr = h->next;
		if (ptr->next)
			ptr->next->prev = h;
		h->next = ptr->next;
		ptr->prev = NULL;
		ptr->next = h;
		h->prev = ptr;
		*stack = ptr;
	}
}
