# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 16:15:13 by dgessner          #+#    #+#              #
#    Updated: 2025/08/18 17:40:47 by dgessner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
all: $(NAME)
$(NAME): $(OBJS)
$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.c philo.h
$(CC) $(CFLAGS) -c $< -o $@
clean:
rm -f $(OBJS)
fclean: clean
rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re