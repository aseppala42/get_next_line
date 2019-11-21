# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aseppala <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 10:09:10 by aseppala          #+#    #+#              #
#    Updated: 2019/11/20 19:51:43 by aseppala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o $(NAME) main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
	rm -f get_next_line.o main.o

fclean: clean
	rm -f $(NAME)

re: fclean all
