#include <stdio.h>

//Ввести строку. Вывести строку так, чтобы за каждым словом следовало количество пробелов, равное длине слова.

int char_index(char c, char* str) {
	int i;

	for (i = 0; str[i] > 0; i++) {
		if (c == str[i]) {
			return i;
		}

	}
	if (c == 0) {
		return i;
	}
	return -1;
}

void add_gaps(char* str, char* separators) {
	int i = 0, j, count = 0, k = 0;
	while (str[i] != 0) {
		if (char_index(str[i], separators) >= 0) {
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
	char* separators = " \t\n,.;:!?/~`@#$%^&*(){}[]\"|'/<>-=_+";

	printf("Input string: ");
	fgets(str, 256, stdin);
	add_gaps(str, separators);

	return 0;
}