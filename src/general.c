/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:49:20 by anlima            #+#    #+#             */
/*   Updated: 2023/09/20 16:34:08 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_term	*term(void);
void	free_env(void);
void	set_env(char **input);

t_term	*term(void)
{
	static t_term	term;

	return (&term);
}

void	set_env(char **input)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (input[i] != NULL)
		i++;
	term()->env = malloc(sizeof(char *) * (i + 1));
	while (++j < i)
		term()->env[j] = ft_strdup(input[j]);
	term()->env[j] = NULL;
}

void	free_env(void)
{
	int	i;

	i = -1;
	while (term()->env[++i] != NULL)
	{
		if (term()->env[i])
			free(term()->env[i]);
	}
	if (term()->env)
		free(term()->env);
}
