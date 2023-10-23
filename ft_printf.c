/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2023/10/23 19:27:26 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printformat(va_list args, char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_length += ft_printdigit(va_arg(args, int), 10, 0);
	else if (format == 'p')
		print_length += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		print_length += ft_printdigit(va_arg(args, unsigned int), 10, 0);
	else if (format == 'x')
		print_length += ft_printdigit(va_arg(args, unsigned int), 16, 0);
	else if (format == 'X')
		print_length += ft_printdigit(va_arg(args, unsigned int), 16, 1);
	else if (format == '%')
		print_length += write(1, "%", 1);
	else
		print_length += write(1, &format, 1);
	return (print_length);

}

int ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int charactercount;

	i=0;
	charactercount = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			charactercount += printformat(args, format[i + 1]);
			i++;
		}
		else
			charactercount += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (charactercount);
}


/*
int main(void) {
	
// Test 2: Printing integers
int num = 42;
	printf("Standard printf: %d\n", num);
	ft_printf("Custom ft_printf: %d\n", num);

	return (0);
}
*/
//cspdiuxX%


/*

// Test 0: CHARACTER
	char *str = "Hello, world
	int message = 109;

	ft_printf("%c\n", message);
	printf("%c\n", message);

// Test 1: Printing strings
	char *str = "Hello, world!";
printf("Standard printf: %s\n", str);
ft_printf("Custom ft_printf: %s\n", str);

// Test 2: Printing integers
int num = 42;
printf("Standard printf: %d\n", num);
//     ft_printf("Custom ft_printf: %d\n", num);

 // Test 3: Printing hexadecimal
int hex = 0x1A3;
printf("Standard printf: %x\n", hex);
ft_printf("Custom ft_printf: %x\n", hex);

// Test 4: Printing pointers
void *ptr = &num;
printf("Standard printf: %p\n", ptr);
ft_printf("Custom ft_printf: %p\n", ptr);

// Test 5: Printing a mix of formats
int a = 10, b = 20, c = 30;
printf("Standard printf: a=%d, b=%d, c=%d\n", a, b, c);
 ft_printf("Custom ft_printf: a=%d, b=%d, c=%d\n", a, b, c);

// Test 6: Printing nulls
int a = 10, b = 20, c = 30;
printf("Standard printf: a=%s, b=%p\n", (char *)NULL, NULL);
ft_printf("Custom ft_printf: a=%d, b=%d, c=%d\n", a, b, c);

*/