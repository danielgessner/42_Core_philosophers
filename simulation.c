/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:39:56 by dgessner          #+#    #+#             */
/*   Updated: 2025/09/14 14:48:57 by dgessner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_philosopher *philo, const char *status)
{
	long	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	time = get_time_ms() - philo->data->start_time;
	if (philo->data->simulation_running)
		printf("%ld %d %s\n", time, philo->id, status);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	init_data(t_data *data)
{
	int	i;

	data->start_time = get_time_ms();
	data->simulation_running = 1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nphilos);
	data->philosophers = malloc(sizeof(t_philosopher) * data->nphilos);
	if (!data->forks || !data->philosophers)
		return (0);
	i = 0;
	while (i < data->nphilos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (0);
	i = 0;
	while (i < data->nphilos)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].meals_eaten = 0;
		data->philosophers[i].last_meal_time = data->start_time;
		data->philosophers[i].left_fork = &data->forks[i];
		data->philosophers[i].right_fork = &data->forks[(i + 1) % data->nphilos];
		data->philosophers[i].data = data;
		i++;
	}
	return (1);
}

void	cleanup_data(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->nphilos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	if (data->philosophers)
		free(data->philosophers);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (philo->data->simulation_running)
	{
		print_status(philo, "is thinking");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		philo->last_meal_time = get_time_ms();
		usleep(philo->data->ttoeat * 1000);
		philo->meals_eaten++;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		print_status(philo, "is sleeping");
		usleep(philo->data->ttosleep * 1000);
	}
	return (NULL);
}

int	create_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nphilos)
	{
		if (pthread_create(&data->philosophers[i].thread, NULL, philosopher_routine, &data->philosophers[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < data->nphilos)
	{
		pthread_join(data->philosophers[i].thread, NULL);
		i++;
	}
	return (1);
}