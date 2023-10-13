NAME = libftprintf.a
SOURCES = \
	ft_printchar.c \
	ft_printf.c \
	ft_printstr.c \
#	ft_printpointer.c \
#	ft_printdigit.c \
	
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
all: $(NAME)
$(NAME): $(OBJECTS)
	$(AR) -r $@ $?
%.o: %.c
	$(CC) -c $(CFLAGS) $?
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all bonus clean fclean re