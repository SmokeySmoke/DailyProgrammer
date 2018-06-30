#include <stdio.h>
#include <stdbool.h>
#define SLEN 25
bool isIE_rule(char * word);

int main(void)
{
	char word[SLEN];
	int fcount = 0;
	int tcount = 0;

	puts("I BEFORE E EXCEPT AFTER C\n");
	do
	{
		printf("Enter a word in lowercase (q to quit): ");
		scanf("%s", word);
		if (word[0] == 'q' && word[1] == '\0')
			break;
		puts(word);
		printf("\t->\t");
		if(isIE_rule(word))
		{
			puts("TRUE");
			tcount++;
		}
		else
		{
			puts("FALSE");
			fcount++;
		}
		while (getchar() != '\n')
			continue;
	} while (1);

	printf("\n%d words processed.\n", tcount + fcount);
	printf("%d words follow the rule,\n", tcount);
	printf("%d words do not follow the rule.\n", fcount);
	puts("Bye!");

	return 0;
}

bool isIE_rule(char * word)
{
	char * pc;
	char ch, next;
	char prevch = '\0';
	bool after_C = false;

	for (pc = word; *pc != '\0'; pc++)
	{
		ch = *pc;
		next = *(pc+1);
		if (prevch == 'c')
			after_C = true;
		if (after_C)
		{
			if (ch == 'i' && next == 'e')
				return false;
		} else
			if (ch == 'e' && next == 'i')
				return false;
		after_C = false;
		prevch = ch;
	}

	return true;
}
