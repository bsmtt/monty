#include "monty.h"

/**
 * get_function - find function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void get_function(char *opcode, char *value, int ln, int format)
{
int i;
int flag;

instruction_t func_list[] = {
{"nop", nop},
{"push", push_stack},
{"pall", pall_stack},
{"pint", print_top},
{"pop", pop_stack},
{"add", add_toptwo_nodes},
{"swap", swap},
{"sub", sub},
{NULL, NULL}
};

if (opcode[0] == '#')
return;

for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
{
if (strcmp(opcode, func_list[i].opcode) == 0)
{
function_handler(func_list[i].f, opcode, value, ln, format);
flag = 0;
}
}
if (flag == 1)
print_error(3, ln, opcode);
}

/**
 * function_handler - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void function_handler(op_func func, char *op, char *val, int ln, int format)
{
stack_t *node;
int flag;
int i;

flag = 1;
if (strcmp(op, "push") == 0)
{
if (val && val[0] == '-')
{
val = val + 1;
flag = -1;
}
if (!val)
print_error(5, ln);
for (i = 0; val[i] != '\0'; i++)
{
if (isdigit(val[i]) == 0)
print_error(5, ln);
}
node = generate_node(atoi(val) * flag);
if (format == 0)
func(&node, ln);
if (format == 1)
push_queue(&node, ln);
}
else
func(&head, ln);
}
/**
 * nop - doesn’t do anything.
 * @stack: Pointer to top node of the stack.
 * @ln: line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int ln)
{
(void)stack;
(void)ln;
}
