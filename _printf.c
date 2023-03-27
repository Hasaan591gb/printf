#include "main.h"

/**
 * _printf - replica of standard library printf function
 * @format: input string
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int i, j, count = 0;
	char c, *str;
	va_list list;

	va_start(list, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
				{
					c = (char)va_arg(list, int);
					count += write(1, &c, 1);
					break;
				}
				case 's':
				{
					str = va_arg(list, char *);
					for (j = 0; str[j] != '\0'; j++)
						count += write(1, &str[j], 1);
					break;
				}
				case '%':
					count += write(1, &format[i], 1);
					break;
			}
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(list);
	return (count);
}
