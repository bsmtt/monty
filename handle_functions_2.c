#include "monty.h"

/**
 * mul - multiple the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error2(8, line_number, "mul");

	mul = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = mul;
	pop_stack(stack, line_number);
}

/**
 * mod - mod the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod(stack_t **stack, unsigned int line_number)
{
        int mod;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                print_error2(8, line_number, "mod");

	if ((*stack)->n == 0)
		print_error2(9, line_number);

        mod = (*stack)->next->n % (*stack)->n;
        (*stack)->next->n = mod;
	pop_stack(stack, line_number);
}
