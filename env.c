#include "shell.h"

/**
 * call_env - Built-in function to print environment variables.
 *
 * @env: Double char pointer containing environment variables.
 *
 * Return: Always returns 1.
 */
int call_env(char **env)
{
    int i = 0;
    int len = 0;
    char *copy = malloc(8192);

    /* Loop through each environment variable */
    while (env[i] != NULL)
    {
        len = _strlen(env[i]);    /* Get the length of the current environment variable */
        copy = _strdup(env[i]);   /* Duplicate the environment variable string */

        /* Write the environment variable and a newline to the standard output */
        write(STDOUT_FILENO, copy, len + 1);
        write(1, "\n", 1);

        /* Free the allocated memory for the duplicated string */
        free(copy);
        i++;  /* Move to the next environment variable */
    }

    /* Always return 1 */
    return (1);
}
