#include <stdio.h>

int main() {
    unsigned long word_count = 0;
    unsigned long line_count = 0;
    unsigned long nbytes = 0;
    char c = '\0';
    while (c != EOF) {
        c = fgetc(stdin);
        nbytes++;
        
        if (c == '\n') {
            line_count++;
            word_count++;
        }
        else if (c == ' ') {
            word_count++;
        }
    }

    printf("\n%ld\t%ld\t%ld", line_count, word_count, nbytes-1);

    return 0;
}
