#include "main.h"
#include <unistd.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_index);

int _printf(const char *format, ...)
{
	int p_chr = 0;
	int i;
	int flags, width, precision, size, buff_index = 0;
	va_list args_list;
	char buffer[BUFF_SIZE];
	
	if (format == NULL)
        return (-1);
	
	va_start(args_list, format);
	
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			p_chr++;
        }
		else
		{
			print_buffer(buffer, &buff_index);
			flags = flags_val(format, &i);
			width = width_val(format, &i, args_list);
			precision = precision_val(format, &i, args_list);
			size = size_val(format, &i);
			i++;
			len += print_hdlr(format, &i, args_list, buffer, flags, width, precision, size);
			if (len == -1)
				return (-1);
			p_chr += len;
		}
	}
	print_buffer(buffer, &buff_index);
	va_end(args_list);
	return (p_chr);
}

void print_buffer(char buffer[], int *buff_index) {
    if (*buff_index > 0) {
        write(1, buffer, *buff_index);
        *buff_index = 0;
    }
}

