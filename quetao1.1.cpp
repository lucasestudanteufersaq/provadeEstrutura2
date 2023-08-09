#include <stdio.h>

int main() {
    int charsPerLine = 10;

    for (int i = 0; i < 128; ++i) {
        printf("%3d: %c   ", i, (char)i);
        
        if ((i + 1) % charsPerLine == 0) {
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}

