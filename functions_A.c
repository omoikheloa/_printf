#include "main.h"
/**
 * print_char - to print character
 * @args_list: arguments
 * @buffer: buffer for handling of prints
 * Return: Number of printed characters
 */

int print_char(va_list args_list, char buffer[])
{
        char c = va_arg(args_list, int);

        return (handle_write_char(c, buffer));
}

/**
 * print_string - to print strings
 * @args_list: arguments
 * @buffer: buffer for handling of prints
 *
 * Return: Number of printed characters
 */

int print_string(va_list args_list, char buffer[])
{
        int length = 0, i;
        char *str = va_arg(args_list, char *);

        if (str == NULL)
        {
                str = "(null)";
        }
        return (write(1, str, length));
}

/**
 * print_percent - to print percent sign
 * @args_list: arguments
 * @buffer: buffer for handling of prints
 *
 * Return: Number of printed characters
 */

int print_percent(va_list args_list, char buffer[])
{
        return (write(1, "%%", 1));
}

/**
 * print_binary - to print integers
 * @args_list: arguments
 * @buffer: buffer for handling of prints
 *
 * Return: Number of printed characters
 */
int print_int(va_list args_list, char buffer[])
{
        int i = BUFF_SIZE - 2;
        int is_negative = 0;
        long int n = va_arg(args_list, long int);
        unsigned long int num;

        n = convert_size_number(n, size);
        if (n == 0)
                buffer[i--] = '0';
        buffer[BUFF_SIZE - 1] = '\0';
        num = (unsigned long int)n;
        if (n < 0)
        {
                num = (unsigned long int)((-1) * n);
                is_negative = 1;
        }
        while (num > 0)
        {
                buffer[i--] = (num % 10) + '0';
                num /= 10;
        }
        i++;
        return (write_number(is_negative, i, buffer);
}

/**
 * print_binary - to print unsigned integers
 * @args_list: arguments
 * @buffer: buffer for handling of prints
 *
 * Return: Number of printed characters
 */
int print_binary(va_list args_list, char buffer[])
{
        unsigned int n, m, i, sum;
        unsigned int a[32];
        int count;

        n = va_arg(args_list, unsigned int);
        m = 2147483648; /* (2 ^ 31) */
        a[0] = n / m;
        for (i = 1; i < 32; i++)
        {
                m /= 2;
                a[i] = (n / m) % 2;
        }
        for (i = 0, sum = 0, count = 0; i < 32; i++)
        {
                sum += a[i];
                if (sum || i == 31)
                {
                        char z = '0' + a[i];

                        write(1, &z, 1);
                        count++;
                }
        }
        return (count);
}
