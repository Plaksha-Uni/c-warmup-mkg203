#include <stdio.h>

int main() {
    unsigned long bytes = 0;
    while (fgetc(stdin) != EOF) {
        bytes++;
    }
    printf("%ld", bytes);
}
