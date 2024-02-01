#include "monty.h"

/**
 * print_error - print error message by error code.
 * @err_number: number of error err_number
 */
void print_error(int err_number, ...)
{
	va_list ag;
	char *instruction;
	int line;

	va_start(ag, err_number);
	switch (err_number)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			line = va_arg(ag, int);
			instruction = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line, instruction);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			line = va_arg(ag, unsigned int);
			instruction = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line, instruction);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
