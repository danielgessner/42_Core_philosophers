/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:15:30 by dgessner          #+#    #+#             */
/*   Updated: 2025/08/18 17:40:56 by dgessner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
// **For each philosopher, consider:**
// - What unique identifier?
// - What timing information?
// - What thread management data?
// - What fork access do they need?

// **For the overall simulation:**
// - What global timing information?
// - What synchronization primitives?
// - What termination conditions?


// Start with these structure templates and fill in the details:
typedef struct s_philosopher
{
    // What does each philosopher need to know about themselves?
    // What do they need to access (forks, shared data)?
} t_philosopher;

typedef struct s_data  
{
    // What shared information do all philosophers need?
    // What synchronization objects do you need?
} t_data;

#endif