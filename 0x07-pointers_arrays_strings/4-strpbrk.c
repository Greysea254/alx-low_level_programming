#include <main.h>

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: The string to search.
 * @accept: The set of bytes to search for.
 *
 * Return: A pointer to the byte in @s that matches one of the bytes in @accept,
 *         or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
	if (s == NULL || accept == NULL)
		return NULL;

	while (*s != '\0')
	{
		char *ptr_accept = accept;
		while (*ptr_accept != '\0')
		{
			if (*s == *ptr_accept)
				return s; /* Found a matching byte, return the pointer to it */
			ptr_accept++;
		}
		s++;
	}

	return NULL; /* No matching byte found */
}
