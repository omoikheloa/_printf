#include "main.h"

/**
 * print_unsigned - Prints an unsigned number.
 * @args_list: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting (e.g., F_PLUS, F_HASH).
 * @width: Minimum width for printing (padding with spaces).
 * @precision: Number of digits after the decimal point
 * (not used for integers).
 * @size: Size specifier for the argument (e.g., h, l, L).
 * Return: Number of characters printed.
 */
int print_unsigned(va_list args_list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args_list, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation.
 * @args_list: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting (e.g., F_PLUS, F_HASH).
 * @width: Minimum width for printing (padding with spaces).
 * @precision: Number of digits after the decimal point
 * (not used for integers).
 * @size: Size specifier for the argument (e.g., h, l, L).
 * Return: Number of characters printed.
 */
int print_octal(va_list args_list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args_list, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	@@ -66,11 +59,11 @@ int print_octal(va_list args_list, char buffer[],
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation.
 * @args_list: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting (e.g., F_PLUS, F_HASH).
 * @width: Minimum width for printing (padding with spaces).
 * @precision: Number of digits after the decimal point
 * (not used for integers).
 * @size: Size specifier for the argument (e.g., h, l, L).
 * Return: Number of characters printed.
 */
int print_hexadecimal(va_list args_list, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(args_list, "0123456789abcdef", buffer, flags, 'x',
			width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation.
 * @args_list: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting (e.g., F_PLUS, F_HASH).
 * @width: Minimum width for printing (padding with spaces).
 * @precision: Number of digits after the decimal point
 * (not used for integers).
 * @size: Size specifier for the argument (e.g., h, l, L).
 * Return: Number of characters printed.
 */
int print_hexa_upper(va_list args_list, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(args_list, "0123456789ABCDEF", buffer,
			flags, 'X', width, precision, size));
}

