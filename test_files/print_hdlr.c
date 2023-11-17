int print_hdlr(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, len2 = 0, p_chr = -1;
	
	struct {
		char fmt;
		int (*fn)(va_list, char *, int, int, int, int);
	} fmt_types[] = {
		{'c', write_char}, {'s', write_string},
		{'%', write_prct}, {'d', write_intgr1},
		{'i', write_intgr2}, {'b', write_bnry},
		{'u', write_unsgnd}, {'o', write_octa},
		{'x', wrie_hexadec}, {'X', write_hexa},
		{'p', write_pntr}, {'S', write_others},
		{'r', write_rvse}. {'R', write_rot13},
		{'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
		{
			return (fmt_types[i].fn(list, buffer, flags,
						width, precision, size));
		}
	}
	if (fmt_types[i].fmt == '\0') 
	{
		if (fmt[*ind] == '\0')
		{
			return (-1);
		}
		len1 += write(1, "%", 1);
		if (fmt[*ind - 1] == ' ')
		{
			len1 += write(1, " ", 1);
		}
		else if (width)
		{
			(*ind)--;
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
			{
				(*ind)--;
			}
			if (fmt[*ind] == ' ')
			{
				(*ind)--;
			}
			return (1);
		}
		len1 += write(1, &fmt[*ind], 1);
		return len1;
	}
	return p_chr;
}
