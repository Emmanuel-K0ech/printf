#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints a string
 * @format: characters passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i;
	va_list list;
	char str;

	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				str = va_arg(list, int);
				_putchar(str);
			}
		}
		else
		{
			_putchar(format[i]);
		}
	}
	va_end(list);
	return (i);
}
