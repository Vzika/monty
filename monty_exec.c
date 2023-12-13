#include "monty.h"
/**
 * execute - executes the given opcode
 * @stack: pointer to the head of a linked list (stack)
 * @counter: line counter
 * @file: pointer to the Monty file
 * @content: content of the line
 * Return: void
 */

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", to_push}, {"pall", print_all}, {"pint", to_pint},
				{"pop", to_remove},
				{"swap", swap_element},
				{"add", addition},
				{"nop", nothing},
				{"sub", subtraction},
				{"div", division},
				{"mul", multiplication},
				{"mod", modulus},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

