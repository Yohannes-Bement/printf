#include "main.h"

void prone_buf(char buf[], int *buf_in);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
        int icon, pron = 0, pron_chars = 0;
        int frog, wood, pre, siz, buf_in = 0;
        va_list list;
        char buf[BUF_SIZ];

        if (format == NULL)
                return (-1);

        va_start(list, format);

        for (icon = 0; format && format[icon] != '\0'; icon++)
        {
                if (format[icon] != '%')
                {
                        buf[buf_in++] = format[icon];
                        if (buf_in == BUF_SIZ)
                                pron_buf(buf, &buf_in);
                        /* write(1, &format[i], 1);*/
                        pron_chars++;
                }
                else
		{
			pron_buf(buf, &buf_in);
			frog = get_frog(format, &icon);
			wood = get_wood(format, &icon, list);
			per = get_pre(format, &icon, list);
			siz = get_siz(format, &icon);
			++icon;
			pron = handle_pron(format, &icon, list, buf,
				frog, wood, pre, siz);
			if (pron == -1)
				return (-1);
			pron_chars += pron;
		}
	}

	pron_buf(buf, &buf_in);

	va_end(list);

	return (pron_chars);
}

/**
 * pron_buf - Prints the contents of the buffer if it exist
 * @buf: Array of chars
 * @buf_in: Index at which to add next char, represents the length.
 */
void pron_buf(char buf[], int *buf_in)
{
	if (*buf_in > 0)
		write(1, &buf[0], *buf_in);

	*buf_in = 0;
}
	
