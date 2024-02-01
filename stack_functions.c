#include "monty.h"

/**
 * push_stack - add node to stack.
 * @new_node: pointer to new node.
 * @ln: line number of of the opcode.
 */
void push_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;

if (!new_node || !*new_node)
exit(EXIT_FAILURE);
if (head)
{
tmp = head;
head = *new_node;
head->next = tmp;
tmp->prev = head;
}
head = *new_node;
}

/**
 * pall_stack - print nodes from stack.
 * @top_node: Pointer to top node of the stack.
 * @ln: line number of  the opcode.
 */
void pall_stack(stack_t **top_node, unsigned int ln)
{
stack_t *tmp;

(void) ln;
if (top_node == NULL)
exit(EXIT_FAILURE);
tmp = *top_node;
while (tmp != NULL)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}
/**
 * print_top - Print top node of the stack.
 * @head: Pointer to top node of the stack.
 * @ln: line number of of the opcode.
 */
void print_top(stack_t **head, unsigned int ln)
{
if (!head || !*head)
print_error2(6, ln);
printf("%d\n", (*head)->n);
}
/**
 * add_toptwo_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @ln: line number of of the opcode.
 */
void add_toptwo_nodes(stack_t **stack, unsigned int ln)
{
if (!stack || !*stack || !(*stack)->next)
print_error2(8, ln, "add");

(*stack) = (*stack)->next;
(*stack)->n = (*stack)->n + (*stack)->prev->n;
free((*stack)->prev);
(*stack)->prev = NULL;
}
