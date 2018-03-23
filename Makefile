# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnunez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/06 18:11:03 by pnunez            #+#    #+#              #
#    Updated: 2018/03/20 18:10:18 by atemunov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ./srcs/check \
	   ./srcs/main \
	   ./srcs/map \
	   ./srcs/read \
	   ./srcs/solve \
	   
CFILES = $(addsuffix .c, $(SRCS))

LIB = ./libft/libft.a

INCLUDE = ./fillit.h

RM = rm -rf

all: $(NAME)

$(LIB):
	@make -C libft

$(NAME): $(LIB)
	$(CC) $(CFLAGS) $(CFILES) $(LIB) -I $(INCLUDE) -o $(NAME)

clean:
	@make -C libft clean

fclean: clean
	$(RM) $(NAME)
	@make -C libft fclean

re: fclean all
