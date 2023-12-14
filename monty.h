#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - Variables including 'arg', 'file', and 'content'
 * @arg: Holds a value
 * @file: Pointer to a file in the Monty system
 * @content: Stores line content
 * @lifi: Flag indicating the stack ↔ queue transition
 * Description: Serves as a carrier for values throughout the program
 */

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void addnode(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void addqueue(stack_t **head, int n);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char  *clean_line(char *content);
void to_push(stack_t **head, unsigned int number);
void print_all(stack_t **head, unsigned int number);
void to_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void to_remove(stack_t **head, unsigned int counter);
void swap_element(stack_t **head, unsigned int counter);
void addition(stack_t **head, unsigned int counter);
void nothing(stack_t **head, unsigned int counter);
void subtraction(stack_t **head, unsigned int counter);
void division(stack_t **head, unsigned int counter);
void multiplication(stack_t **head, unsigned int counter);
void modulus(stack_t **head, unsigned int counter);
#endif

