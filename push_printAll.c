#include "monty.h"
/**
 * to_push - function to add a node to the stack
 * @head: pointer to the stack head
 * @counter: line number
 * Return: void
 */

void to_push(stack_t **head, unsigned int counter)
{
	int number, count= 0, flag = 0;

	if (bus.arg)/*to check if bus.arg is not NULL*/
	{
		if (bus.arg[0] == '-')
			count++;
		for (; bus.arg[count] != '\0'; count++)
		{
			if (bus.arg[count] > 57 || bus.arg[count] < 48)/*to check if bus.arg is out of range of char,'0'is 48, '9'is 57*/
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	number = atoi(bus.arg);/*to convert the char into integer*/
	if (bus.lifi == 0)
		addnode(head, number);
	else
		addqueue(head, number);
}

/**
 * print_all - function to print the stack
 * @head: pointer to the stack head
 * @counter: not used
 * Return: void
 */

void print_all(stack_t **head, unsigned int counter)
{
	stack_t *temp;/*temporal pointer to transverse through the loop*/
	(void)counter;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

