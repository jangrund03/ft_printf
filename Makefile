NAME = libftprintf.a
CC = cc
CFLAGS =	 -Wall -Wextra -Werror
SRC = ft_printf_utils.c\
	ft_printf.c\

OBJ = $(SRC:.c=.o)

all:	 $(NAME)

$(NAME):	 $(OBJ)
	ar -rv $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
