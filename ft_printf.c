/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2023/10/13 14:50:41 by cberneri         ###   ########.fr       */
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
	else if (format == 'd')
		printf("d");
//		print_length += ft_printdigit(va_arg(args, int), 10, 0);
	else if (format == 'i')
		printf("TEST3");
//		print_length += ft_printdigit(va_arg(args, int), 10, 0);
	else if (format == 'p')
		printf("TEST4");
//		print_length += ft_printpointer(va_arg(args, unsigned long long));
	else if (format == 'u')
		printf("TEST5");
//		print_length += ft_printdigit(va_arg(args, unsigned int), 10, 0);
	else if (format == 'x')
		printf("TEST6");
//		print_length += ft_printdigit(va_arg(args, unsigned int), 16, 0);
	else if (format == 'X')
		printf("TEST7");
//		print_length += ft_printdigit(va_arg(args, unsigned int), 16, 1);
	else if (format == '%')
		printf("TEST8");
//		print_length += write(1, "%", 1);
	else
		printf("TEST9");
//		print_length += write(1, &format, 1);
	return (print_length);

}



//int ft_printf(const char *, ...);
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

int main() {
	//const char *message = "Hello12312, World!";
	char *message = "D";

	ft_printf("%c", message);
	//printf("%c", message);
	
	//printf("total is: %d", ft_bzero("333"));

	
	return (0);

/*
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
}

/* 
	else if (format == 'e')
		print_length += printeeeeeeee(va_arg(args, char *));
	else if (format == 'E')
		print_length += printeeeeeeee(va_arg(args, char *));
	else if (format == 'f')
		print_length += printFFFFFFFFF(va_arg(args, char *));
	else if#include "libft.h"
#include <stdarg.h>

int ft_printf(const char *, ...)
{

	va_start(args, fmt);

}

int main(void)
{
	printf("total is: %d", ft_bzero("333"));
} (format == 'g')
		print_length += printggggggggg(va_arg(args, char *));
	else if (format == 'G')
		print_length += printGGGGGGGGG(va_arg(args, char *));
	else if (format == 'n')
		print_length += printNNNNNN(va_arg(args, char *));
	else if (format == 'o')
		print_length += printOOOOOOOOO(va_arg(args, char *));
	else if (format == 'p')
		print_length += printptr(va_arg(args, unsigned long long));
	else if (format == 's')
		print_length += printstr(va_arg(args, char *));
	else if (format == 'u')
		print_length += printUUUUUUUU(va_arg(args, char *));
	else if (format == 'x' || format == 'X')
		print_length += printhexadecimal(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += printpercent();
*/