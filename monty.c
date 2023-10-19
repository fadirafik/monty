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
		printf("Error: malloc failed\n");
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

	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
