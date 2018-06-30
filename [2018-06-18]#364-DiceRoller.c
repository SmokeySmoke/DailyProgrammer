/* DiceRoller.c -- rolls n dice with x sides and displays result */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define SLEN 32
unsigned DiceRoll(const unsigned nsides);

int main(void)
{
	unsigned ndice, nsides, i, mod, sum, temp;
	char string[SLEN];

	puts("Enter a string in the form ndx, where n is the number of dice to roll\n"
	     "and x is the number of sides on each die (EOF to quit):");
	while (scanf("%s", string) == 1)
	{
		for (mod = 1, sum = ndice = nsides = i = 0; string[i] != '\0'; i++)
		{
			if (string[i] == 'd')
			{
				ndice = sum;
				sum = 0;
				mod = 1;
			}
			else
			{
				if ((temp = string[i] - '0') == 0)
					sum *= 10;
				else
					sum += temp * mod;
				mod *= 10;
			}
		}
		nsides = sum;
		for (sum = i = 0; i < ndice; sum += temp, i++)
		{
			if ((i % 10) + 1 == 1)
				putchar('\n');
			printf("%4u ", temp = DiceRoll(nsides));
		}
		putchar('\n');
		if (sum != 0)
			printf("\n%s: %u\n", string, sum);
		else
			printf("\nIncorrect format detected! Try again.\n");
		printf("\nEnter another string (EOF to quit): ");
	}
	puts("Done!");

	return 0;
}

unsigned DiceRoll(const unsigned nsides)
{
	unsigned sum = 0;
	srand((unsigned) clock());

	return (rand() % nsides) + 1;
}
