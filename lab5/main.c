#include <stdio.h>

void add_gaps(char* str) {
	int i = 0, j, count = 0, k = 0;
	while (str[i] != 0) {
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0' || str[i] == '\t') {
			for (j = count; j != 0; j--) {
				printf("%c", ' ');
			}
			count = 0;
			i++;
		}
		else {
			printf("%c", str[i]);
			i++;
			count++;
			k++;
		}
	}

	if (k == count) {
		printf("No words\n");
	}
	else {
		printf("%c", '.');
	}
}

int main()
{
	char str[256];
	printf("Input string: ");
	fgets(str, 256, stdin);
	add_gaps(str);

	return 0;
}