#include "main.h"

/**
 * _printf - Printf function
 * @format: format
 *
 * Return: length of printed character
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, p_chara = 0;
	int buffer_index = 0;
	va_list args_list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFFER_SIZE)
				print_buffer(buffer, &buffer_index);
			p_chara++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			++i;
			if (print_func(format, &i, args_list, buffer) == -1)
			{
				va_end(args_list);
				return (-1);
			}
			p_chara += buffer_index;
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(args_list);

	return (p_chara);
}
