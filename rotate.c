#include "monty.h"
/**
 * rotate_top - Rotates the stack to bring the top element to the front
 * @head: Pointer to the stack's head
 * @counter: Line number
 * Return: No return value
 */

void rotate_top(stack_t **head,  __attribute__((unused)) unsigned int counter)
{

	stack_t *tmp = *head, *new_node;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	new_node = (*head)->next;
	new_node->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = new_node;
}

#include "monty.h"
/**
 * rotate_botom - Rotates the stack to move the top element to the bottom
 * @head: Pointer to the stack's head
 * @counter: Line number
 * Return: No return value
 */

void rotate_botom(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}

