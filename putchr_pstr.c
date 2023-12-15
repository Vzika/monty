#include "monty.h"
/**
 * put_char - Prints the character at the top of the stack
 *           followed by a new line
 * @head: Pointer to the stack's head
 * @counter: Line number
 * Return: No return value
 */

void put_char(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	temp = *head;
	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (temp->n > 127 || temp->n < 0)/*In the ASCII character set, values range from 0 to 127 for standard characters*/
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}

#include "monty.h"
/**
 * print_string - Outputs the string beginning at the top of the stack,
 *          followed by a new line
 * @head: Pointer to the stack's head
 * @counter: Line number
 * Return: No return value
 */

void print_string(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	(void)counter;

	temp = *head;
	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

