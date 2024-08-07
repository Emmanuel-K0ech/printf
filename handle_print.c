#include "main.h"
/**
 * handle_print - Prints an argument based on - its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: indx.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags -actvie
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 2 or 1
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_charr}, {'s', printt_string}, {'%', printt_percent},
		{'i', printt_int}, {'d', printt_int}, {'b', printt_binary},
		{'u', printt_unsigned}, {'o', printt_octal}, {'x', printt_hexadecimal},
		{'X', printt_hexa_upper}, {'p', printt_pointer}, {'S', printt_non_printable},
		{'r', printt_reverse}, {'R', printt_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
