#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	char *opcode;
	int value;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		/* Parse the line and execute the corresponding operation */
		strtok(line, "\n");
		opcode = strtok(line, " ");
		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				char *arg = strtok(NULL, " ");
				if (arg == NULL)
				{
					fprintf(stderr, "Error: Push requires an argument\n");
					exit(EXIT_FAILURE);
				}
				value = atoi(arg);
				push(&stack, value);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stack, 0);
			}
		}
	}

	fclose(file);
	free(line);
	free_stack(stack);

	return (EXIT_SUCCESS);
}

/**
 * free_stack - Frees a stack_t stack
 * @stack: Pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		temp->prev = NULL;
		temp->next = NULL;
		free(temp);
	}
}

