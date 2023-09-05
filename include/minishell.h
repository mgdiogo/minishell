/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:48:28 by anlima            #+#    #+#             */
/*   Updated: 2023/09/02 11:54:57 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define RED "\033[91;1m"
# define GREEN "\033[92;1m"
# define YELLOW "\033[93;1m"
# define BLUE "\033[94;1m"
# define PINK "\033[95;1m"
# define CLEAR "\033[0m"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <dirent.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# define MAX_TOKENS 100
# define MAX_TOKEN_LENGTH 100

extern char	**environ;

typedef struct s_term
{
	char	*user;
	char	*home;
	char	*command;
	char	**cmd_table;
	char	**env;
	char	**tokens;
}			t_term;

// buitins
void		execute_exit(void);
void		execute_echo(void);
void		execute_clear(void);
void		execute_ls(char *str);
void		execute_cd(void);
void		execute_pwd(void);
void		execute_env(void);
void		execute_unset(void);
void		execute_export(void);
// parser
int			is_special_char(char c);
void		trim_argument(char **arg);
void		handle_token(int *i, int *j);
int			is_token(char *input, int i);
void		handle_quotes(int *i, int *j);
void		toggle_state(char *input, int i, int *single_quotes,
				int *double_quotes);
void		lexer(void);
int			is_valid_command(char *token);
void		parser(void);
// free memory
void		clean_mallocs(void);
// general
t_term		*term(void);
// lexer
int			is_delimiter(char c);
// signals
void		handle_sigint(int signum);

#endif