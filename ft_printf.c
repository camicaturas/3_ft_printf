/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2023/06/22 11:17:03 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// UNDER CONSTRUCTION


#include <stdio.h>
#include <stdarg.h>
#include "../01_libft/libft.h"

int	printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printstr(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printptr(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printnbr(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printunsigned(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printhexadecimal(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printpercent(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printformat(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += printchar(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		print_length += printnbr(va_arg(args, int));
	else if (format == 'e')
		print_length += printeeeeeeee(va_arg(args, char *));
	else if (format == 'E')
		print_length += printeeeeeeee(va_arg(args, char *));
	else if (format == 'f')
		print_length += printFFFFFFFFF(va_arg(args, char *));
	else if (format == 'g')
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
	return (print_length);
}



//int ft_printf(const char *, ...);
int ft_printf(const char *format, ...)
{
	//format is the last known parameter of the function
	//const char *argument;
	va_list args;
    int i;
	int charactercount;

    int i;
	charactercount = 0;
	va_start(args, format);
	//argument = va_arg(args, const char *);

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
	const char *message = "Hello12312, World!";
	ft_printf("%s", message);
	return 0;
}

/*

#include "libft.h"
#include <stdarg.h>

int ft_printf(const char *, ...)
{

	va_start(args, fmt);

}

int main(void)
{
	printf("total is: %d", ft_bzero("333"));
}
*/




/*
1) Escanear el string para definir CANTIDAD de SUBARGUMENTOS
2) interpretar SUBARG y encontrar el caso correspondiente (%s por ejemplo)
3) Asignar variable [VAR] a SUBARGUMENTO (punto 2)
4) Se convierte a STRING (se mallocea y se liberia la memoria luego, creo...)



Funciones globales extra:
ft_putchar_fd.c Imprime caracter %c
ft_putstr_fd.c Imprime string %s
ft_putnbr_fd.c (creo que se llama asi) Imprime num %d
ft_itoa.c De int a char %i

	-- hay que hacer:
  • %p The void * pointer argument has to be printed in hexadecimal format
  • %u Prints an unsigned decimal (base 10) number
  • %x Prints a number in hexadecimal (base 16) lowercase format.
	• %X Prints a number in hexadecimal (base 16) uppercase format.
	• %% Prints a percent sign.


Funciones estaticas extra:

1. Para escanear todos los argumentos. Lleno de if-else
 aca se usa va arg?
 
 int(?) printarg(va_list arg, char c) //por que seria un int? puede ser otra cosa? por que?
 {
 	
  
    if (c == 'c')
        ft_putchar_fd();
    if (c == 's')
        ft_putstr_fd();
    if (c == 'd')
        ft_putnbr_fd();
    if (c == 'i')
        ft_itoa();
    if (c == 'p')
        ft_putpointer();
    if (c == 'u')
        ft_putundec();
    if (c == 'x')
        ft_lowhex();
    if (c == 'X')
        ft_upphex();
        

 }

*/