/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:15:30 by dgessner          #+#    #+#             */
/*   Updated: 2025/09/14 13:21:22 by dgessner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
// **For each philosopher, consider:**
// - What unique identifier?
// - What timing information?
// - What thread management data?
// - What fork access do they need?

// **For the overall simulation:**
// - What global timing information?
// - What synchronization primitives?
// - What termination conditions?


typedef struct s_data	t_data;

typedef struct s_philosopher
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
} t_philosopher;

typedef struct s_data
{
	int				nphilos;
	int				ttodie;
	int				ttoeat;
	int				ttosleep;
	int				nmeals;
	long			start_time;
	int				simulation_running;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	t_philosopher	*philosophers;
} t_data;

// Parsing functions
int		ft_atoi(const char *str);
int		ft_isdigit(int a);
int		is_all_digits(const char *str);
int		check_all_argv_digits(int argc, char **argv);
int		fill_data(t_data *data, int argc, char **argv);
int		validate_arguments(int argc, char **argv);
void	error_handling(int errorcode);

// Simulation functions
int		init_data(t_data *data);
void	cleanup_data(t_data *data);
long	get_time_ms(void);
void	*philosopher_routine(void *arg);
int		create_philosophers(t_data *data);
void	print_status(t_philosopher *philo, const char *status);

#endif