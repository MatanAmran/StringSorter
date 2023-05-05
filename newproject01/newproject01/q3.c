#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define stringlen 256

int isJumble(char*);

main()
{
	char string[stringlen], longstring[stringlen], end[] = "end", End[] = "End";
	int long_s_size = 0, templength;

	printf("write a sentence(series of strings)end with ''End'' please: ");
	if (scanf("%s", string) != 1)
		return 1;
	long_s_size = strlen(string);

	while (strcmp(string, End) != 0)
	{
		if (isJumble(string))
		{
			if (strlen(string) > long_s_size)
			{
				strcpy(longstring, string);
				long_s_size = strlen(longstring);
			}
		}
		rewind(stdin);
		printf("write a sentence(series of strings)end with ''End'' please: ");
		if (scanf("%s", string) != 1)
			return 1;
	}
	if (long_s_size)
		printf("The word %s is the biggest jumble word and her length: %d", longstring, long_s_size);
	else
		printf("goodbye");

	return 0;
}

int isJumble(char* string)
{
	int i, lengthstr = strlen(string);
	int counterlist[26] = { 0 };

	for (i = 0; i < lengthstr; i++)
	{
		if ((string[i] == (string[i + 1] + 1)) || (string[i] == (string[i + 1] - 1)))
			return 0;
		else
			counterlist[string[i] - 'a'] += 1;
	}
	for (i = 0; i < 26; i++)
	{
		if (counterlist[i] > 1)
			return 0;
	}

	return 1;

}