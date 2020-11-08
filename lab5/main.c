#include <stdio.h>
#include <stdlib.h>

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

void push(char* words[1000], char* str, int start, int end) {
    int len = end - start;
    int i, word_index;

    if (len < 1) {
        return;
    }
    char* word;

    word = (char*)malloc((len + 1) * sizeof(*word));

    if (word == NULL) {
        printf("Allocation error");
        exit(1);
    }

    word[len] = 0; 
    for (i = 0; i < len; i++) {
        word[i] = str[start + i];
    }

    for (word_index = 0; word_index < 1000; word_index++) {
        if (words[word_index] == NULL) {
            break;
        }
    }
    words[word_index] = word;
}

void split(char* words[1000], char* str, char* separators) {
    int i, start = 0;

    for (i = 0; i < 1000; i++) {
        words[i] = NULL;
    }

    for (i = 0; ; i++) {
        if (char_index(str[i], separators) >= 0) {
            push(words, str, start, i);
            start = i + 1;
        }
        if (str[i] == 0) {
            break;
        }
    }
}

void double_spase(char* words[1000]) {
    int i, len = 0, j;
    char* w;
    for (i = 0; words[i] != NULL; i++) {
        len = char_index(0, words[i]);

        w = (char*)realloc(words[i], 2 * len + 1);

        if (w == NULL) {
            printf("Allocation error");
            exit(1);
        }

        for (j = len; j < 2 * len; j++) {
            w[j] = ' ';
        }
        w[2 * len] = 0;
        words[i] = w;
    }
}

int main() {
   
    int i;
    char* separators = " \t\n,.;:!?/~`@#$%^&*(){}[]\"|'/<>-=_+";
    char* words[1000];
    char str[256];

    printf("Input string: ");
    fgets(str, 256, stdin);

    split(words, str, separators);

    if (words[0] == NULL) {
        printf("No words\n");
        return 0;
    }
    double_spase(words);

    for (i = 0; words[i] != NULL; i++) {
        printf("%s", words[i]);
    }
    printf("%c", '.');

    return 0;
}