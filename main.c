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
	if (!init_data(&data))
	{
		printf("Error: Failed to initialize data structures\n");
		cleanup_data(&data);
		return (1);
	}
	create_philosophers(&data);
	cleanup_data(&data);
	return (0);
}