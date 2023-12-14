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
	instruction_t op_arr[] = {
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
	char *op_code;

	op_code = strtok(content, " \n\t");/*to tokenize the content of the file after being read*/
	if (op_code && op_code[0] == '#')/*check if it is a comment*/
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (op_arr[i].opcode && op_code)
	{
		if (strcmp(op_code, op_arr[i].opcode) == 0)
		{	op_arr[i].f(stack, counter);/*call the corresponding function*/
			return (0);
		}
		i++;
	}
	if (op_code && op_arr[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op_code);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

