#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

unsigned int	ft_random_number(int maxn)
{
	unsigned int	r;
	struct	timeval t;

	gettimeofday(&t, NULL);
	unsigned int seed = t.tv_sec * 1000000 + t.tv_usec;
	srand(seed);

	r = rand() % (maxn + 1);
	return (r);
}

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

int	ft_frandom_word(char *filename)
{
	FILE	*f;
	int	counter;
	unsigned int	flines;
	unsigned int	r;
	unsigned int	c;
	int	capital;

	capital = 1;
	f = fopen(filename, "r");
	flines = ft_fcount_lines(f);
	r = ft_random_number(flines);
	if (!f)
	{
		perror(filename);
		return (1);
	}

	f = fopen(filename, "r");
	counter = 0;
	while ((c = fgetc(f)) != EOF)
	{
		if ((counter == r) && (c != '\n'))
		{
			if (capital == 1)
			{
				printf("%c", c - 32);
				capital = 0;
			}
			else
				printf("%c", c);
		}
		if (c == '\n')
			counter++;
	}
	fclose(f);
	return (0);
}

int	main(int argc, char **argv)
{
	int	ncount;

	if (argc != 2)
		return (0);
	ncount = atoi(argv[1]);
	for (int n = 0; n < ncount; n++)
	{
		ft_frandom_word("adjectives.txt");
		ft_frandom_word("nouns.txt");
		printf("\n");
	}

	return (0);
}
