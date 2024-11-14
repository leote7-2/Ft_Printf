# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 12:38:08 by jhenriq2          #+#    #+#              #
#    Updated: 2024/05/07 16:19:39 by jhenriq2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRCS = 	ft_printf.c ft_aux.c
OBJS = $(SRCS:.c=.o)
RM = rm -f $(OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFALGS) -c $< -o $@

clean:
	$(RM)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re