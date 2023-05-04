#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 51
char letterAtIndex(char*, int);
main()
{
	char string[N], returnChar;
	int m;

	printf("Enter string(not more than 50 chars), please: ");
	if (scanf("%s", string) != 1)
		return 1;

	printf("Enter any index in the string, please: ");
	if (scanf("%d", &m) != 1)
		return 1;
	returnChar = letterAtIndex(string, m);
	printf("The index char in organized string is: %c", returnChar);
	return 0;
}
char letterAtIndex(char* string, int index)
{
	int counterlist[26] = { 0 };
	int i, len_str;

	len_str = strlen(string);

	for (i = 0; i < len_str; i++)
		counterlist[string[i] - 'a'] += 1;

	for (i = 0;;)
	{
		index -= counterlist[i];

		if (index < 1)
			return (i + 'a');
	}
}