#include "monty.h"

/**
 * main - monty interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *fp;
	char line[1024];
	unsigned int lin = 0;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), fp))
	{
		stack = execute(line, stack, lin);
		lin++;
	}

	fclose(fp);
	free_stack(stack);
	return (0);
}
/**
 * execute - executes the functions of the line
 * @string: line to be parsed and executed
 * @stack: pointer to a stack linked list
 * @line_n: line of the file
 * Return: nothing
*/
stack_t *execute(char *string, stack_t *stack, unsigned int line_n)
{
	int i = 0;
	instruction_t st[] = {
		{"pall", pall},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{"pop", pop},
		{"null", NULL}
	};
	char *firstword;
	char *secondword;

	firstword = strtok(string, " \n");
	secondword = strtok(NULL, " \n");
	if (!strcmp(firstword, "push"))
	{
		if (secondword == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			exit(EXIT_FAILURE);
		}
		push(&stack, atoi(secondword), line_n);
	}
	else if (!strcmp("nop", firstword))
	;
	else
	{
		while (strcmp(st[i].opcode, "null") != 0)
		{
			if (!strcmp(st[i].opcode, firstword))
			{
				st[i].f(&stack, line_n);
				return (stack);
			}
			i++;
		}
		fprintf(stderr, "L%u: unknown instruction %s\n", line_n, firstword);
	}
	return (stack);
}
