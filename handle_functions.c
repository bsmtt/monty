#include "monty.h"

/**
* pop_stack - Delete top of list
* @stack: Double linked list
* @line_number: File line execution
*/
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double linked list
 * @line_number: File line execution
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * sub - sub the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error2(8, line_number, "sub");

	sub = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = sub;
	free((*stack)->next->prev);
	(*stack)->next->prev = NULL;
}
