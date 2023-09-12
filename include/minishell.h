/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:48:28 by anlima            #+#    #+#             */
/*   Updated: 2023/09/12 22:43:36 by anlima           ###   ########.fr       */
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

typedef struct s_command
{
	char				*command;
	struct s_command	*left;
	struct s_command	*right;
}						t_command;

typedef struct s_term
{
	char				*user;
	char				*home;
	char				**env;
	char				*command;
	char				**cmd_table;
	t_command			*command_tree;
}						t_term;

// buitins
void					execute_exit(void);
void					execute_echo(char *token);
void					execute_clear(void);
void					execute_ls(char *str);
void					execute_cd(void);
void					execute_pwd(void);
void					execute_env(void);
void					execute_unset(void);
void					execute_export(void);
// executor
void					executor(void);
// parser
void					trim_argument(char **arg);
void					handle_token(int *i, int *j);
int						is_inside_quotes(char *input, int i);
void					lexer(void);
char					opened_quote(char *str);
void					handle_quotes(char **arg);
int						is_valid_argument(char *arg);
int						is_valid_red(char **tokens, int i);
void					parser(void);
// utils
void					free_commands(t_command *root);
void					print_commands(t_command *root);
t_command				*create_command_node(char *command);
void					insert_node(t_command **root, char *command);
// free memory
void					clean_mallocs(void);
// general
t_term					*term(void);
// signals
void					handle_sigint(int signum);

#endif