#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void nop(stack_t **, unsigned int);
void add_toptwo_nodes(stack_t **, unsigned int);
void print_error(int err_number, ...);
void print_error2(int err_number, ...);
void print_top(stack_t **head, unsigned int ln);
stack_t *generate_node(int);
void push_queue(stack_t **, unsigned int);
void pall_stack(stack_t **, unsigned int);
void push_stack(stack_t **, unsigned int);
void get_function(char *, char *, int, int);
void function_handler(op_func, char *, char *, int, int);
void free_nodes(void);
int parse_line(char *, int, int);
void _fread(FILE *);
void _fopen(char *);
void pop_stack(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_stack(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
#endif /* monty.h */
