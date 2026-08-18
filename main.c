#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	ft_fcount_lines(FILE *f)
{
	int	c;
	int	count;

	count = 0;
	while ((c = fgetc(f)) != EOF)
	{
		if (c == '\n')
			count++;
	}

	return (count);
}

int	ft_adj(void)
{
	FILE	*adj;
	int	counter;
	int	r;
	int	c;

	counter = 0;
	adj = fopen("adjectives.txt", "r");
	srand(time(NULL));
	r = rand() % (ft_fcount_lines(adj) + 1);
	if (!adj)
	{
		perror("adjectives.txt");
		return (1);
	}

	adj = fopen("adjectives.txt", "r");
	while ((c = fgetc(adj)) != EOF)
	{
		if ((counter == r) && (c != '\n'))
			printf("%c", c);
		if (c == '\n')
			counter++;
	}
	return (0);
}

int	ft_noun(void)
{
	FILE	*noun;
	int	counter;
	int	r;
	int	c;

	counter = 0;
	noun = fopen("nouns.txt", "r");
	srand(time(NULL));
	r = rand() % (ft_fcount_lines(noun) + 1);
	if (!noun)
	{
		perror("nouns.txt");
		return (1);
	}

	noun = fopen("nouns.txt", "r");
	while ((c = fgetc(noun)) != EOF)
	{
		if ((counter == r) && (c != '\n'))
			printf("%c", c);
		if (c == '\n')
			counter++;
	}
	return (0);
}

int	main(void)
{
	ft_adj();
	ft_noun();
	printf("\n");

	return (0);
}
