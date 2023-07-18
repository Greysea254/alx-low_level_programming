#include "main.h"


	/**
	 * description:	print_alphabet - print all alphabet in lowercase
	 * return: none
	 */


	void print_alphabet(void)
	{
		char letter;


		for (letter = 'a'; letter <= 'z'; letter++)
			_putchar(letter);


		_putchar('\n');
	}
