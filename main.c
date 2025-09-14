/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:16:38 by dgessner          #+#    #+#             */
/*   Updated: 2025/09/14 13:51:58 by dgessner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	isneg;

	result = 0;
	isneg = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == ('-') || *str == '+')
	{
		if (*str == '-')
			isneg = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10 + (*str - '0'));
		str++;
	}
	if (isneg == 1)
		result = result * -1;
	return (result);
}

int	ft_isdigit(int a)
{
	if (a <= '9' && a >= '0')
		return (1);
	return (0);
}

int	is_all_digits(const char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
/*
** Checkes Error Message Handling
** Code 1 = Wrong Number of Arguments;
*/
void	error_handling(int errorcode)
{
   if (errorcode == 1)
   {
        printf("You need to run the progromm with the following Arguments:\n");
        printf("[1] number of philosophers\n");
        printf("[2] time_to_die\n");
        printf("[3] time_to_eat\n");
        printf("[4] time_to_sleep\n");
        printf("[5] optional: meals each philo eats\n");
   }
   if (errorcode == 2)
   {
        printf("The Input must be in the form of a positve Integer e.g. 42\n");
   }
}
/*
** Validates command line arguments for the philosophers simulation
** Arguments must be: philosophers, time_to_die, time_to_eat, time_to_sleep, [meals]
** All arguments must be positive integers
*/
// typedef struct s_data  
// {
//     int		nphilos;
// 	int		ttodie;
// 	int		ttoeat;
// 	int		ttosleep;
// 	int		nmeals;
//     // What shared information do all philosophers need?
//     // What synchronization objects do you need?
// } t_data;
int	check_all_argv_digits(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_all_digits(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	fill_data(t_data *data, int argc, char **argv)
{
	data->nphilos = ft_atoi(argv[1]);
	data->ttodie = ft_atoi(argv[2]);
	data->ttoeat = ft_atoi(argv[3]);
	data->ttosleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nmeals = ft_atoi(argv[5]);
	else
		data->nmeals = -1;
	return (1);
}

static int	validate_arguments(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		error_handling(1);
		return (0);
	}
	if (!check_all_argv_digits(argc, argv))
    {
        error_handling(2);
		return (0);
    }
	return (1);
}

/*
** Main entry point for the philosophers simulation
** Validates arguments, initializes data structures, runs simulation, and cleans up
*/
int	main(int argc, char **argv)
{
	t_data	data;

	if (!validate_arguments(argc, argv))
		return (1);
	fill_data(&data, argc, argv);
	return (0);
}