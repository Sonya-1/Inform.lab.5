#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char enc_char(char c, int step) {

	int i = (int)c + step;

	while (i > 127) {
		i -= 127;
	}
	while (i < 0) {
		i += 127;
	}

	return (char)i;
}

void encode(char* str, int step) {
	int i = 0;
	while (str[i] != '\0') {
		str[i] = enc_char(str[i], step);
		i++;
	}
}

void decode(char* str, int step) {
	int i = 0;
	step = -step;
	while (str[i] != '\0') {
		str[i] = enc_char(str[i], step);
		i++;
	}
}

int main() {

	char str[256];
	int i;

	printf("Input string: ");
	fgets(str, 256, stdin);

	printf("Input shift: ");
	int sf_res = scanf("%i", &i);

	if (sf_res == 0) {
		char c;
		if (1 == scanf("%c", &c)) {
			printf("Incorrect input of shift \"%c\"\n", c);
			return 0;
		}
	}

	encode(str, i);
	printf("Encode: %s\n", str);

	decode(str, i);
	printf("Decode: %s\n", str);

	return 0;
}