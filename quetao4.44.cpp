#include <stdio.h>

int isPerfect(int num) {
    int somaFatores = 0;

    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            somaFatores += i;
        }
    }

    return somaFatores == num;
}

int main() {
    printf("Números perfeitos entre 1 e 1000:\n");

    for (int num = 1; num <= 1000; num++) {
        if (isPerfect(num)) {
            printf("%d é um número perfeito. Fatores: 1", num);

            for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                    printf(" + %d", i);
                }
            }

            printf("\n");
        }
    }

    return 0;
}

