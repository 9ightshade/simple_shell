#include "shell.h"

/**
 * parse_line - Uses strtok to put args in array
 *
 * @line: char pointer
 *
 * Return: Double char pointer
 */
char **parse_line(char *line)
{
    /* Initial size for token array */
    int buffer_size = BUFFERSIZE;
    
    /* Index to keep track of token location */
    int location = 0;

    /* Array to store tokens */
    char **tokens = NULL;

    /* Temporary storage for each token */
    char *token = NULL;

    /* Allocate memory for the tokens array */
    tokens = malloc(sizeof(char *) * buffer_size);
    if (!tokens)
    {
        perror("hsh");
        exit(EXIT_FAILURE);
    }

    /* Use strtok to tokenize the input line */
    token = strtok(line, DELIMINATOR);

    /* Loop through the tokens */
    while (token != NULL)
    {
        /* Store the token in the array */
        tokens[location] = token;

        /* Get the next token */
        token = strtok(NULL, DELIMINATOR);

        /* Increment the location */
        location++;

        /* Check if the array needs to be resized */
        if (location >= buffer_size)
        {
            buffer_size += BUFFERSIZE;

            /* Reallocate memory for the tokens array */
            tokens = _realloc(tokens, buffer_size * sizeof(char *));

            /* Check if reallocation was successful */
            if (!tokens)
            {
                perror("hsh: allocation error\n");
                exit(EXIT_FAILURE);
            }

            /* Get the next token */
            token = strtok(NULL, DELIMINATOR);
        }
    }

    /* Set the last element to NULL to mark the end of the array */
    tokens[location] = NULL;

    return (tokens);
}
