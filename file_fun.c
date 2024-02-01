#include "monty.h"

/**
 * _fopen - opens a file
 * @file: the file namepath
 * Return: void
 */
void _fopen(char *file)
{
	FILE *fd = fopen(file, "r");

	if (file == NULL || fd == NULL)
		print_error(2, file);

	_fread(fd);
	fclose(fd);
}

/**
 * _fread - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */
void _fread(FILE *fd)
{
	int ln, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (ln = 1; getline(&buffer, &len, fd) != -1; ln++)
	{
		format = parse_line(buffer, ln, format);
	}
	free(buffer);
}

/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @ln: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parse_line(char *buffer, int ln, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (!buffer)
		print_error(4, ln);

	opcode = strtok(buffer, delim);
	if (!opcode)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	get_function(opcode, value, ln, format);
	return (format);
}
