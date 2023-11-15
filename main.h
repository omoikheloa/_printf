#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024


/**
 * struct fmt - Struct op
 * @fmt: The format.
 * @fn: The function associated.
 */

typedef struct fmt
{
	char fmt;
	int ((*fn)(va_list, char[]));
}t;

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int print_func(const char *fmt, int *ind, va_list args_list, char buffer[]);

int print_char(va_list args_list, char buffer[]);
int print_string(va_list args_list, char buffer[]);
int print_percent(va_list args_list, char buffer[]);
int print_int(va_list args_list, char buffer[]);
int print_binary(va_list args_list, char buffer[]);
int print_unsigned(va_list args_list, char buffer[]);
int print_octal(va_list args_list, char buffer[]);
int print_hexadecimal(va_list args_list, char buffer[]);
int print_hexa_upper(va_list args_list, char buffer[]);
int print_rot13string(va_list args_list, char buffer[], 
		int flags, int width, int precision, int size);
int print_reverse(va_list args_list, char buffer[], int flags, 
		int width, int precision, int size);
int print_pointer(va_list args_list, char buffer[], int flags, 
		int width, int precision, int size);
int print_non_printable(va_list args_list, char buffer[], int flags, 
		int width, int precision, int size);
int print_hexa(va_list args_list, char map_to[], char buffer[], int flags, 
		char flag_ch, int width, int precision, int size);
int handle_write_char(char c, char buffer[], int flags, int width, 
		int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags, 
		int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision, 
		int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width, int flags, 
		char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, 
		int precision, int size);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
