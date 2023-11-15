#include <stdio.h>

void printBinary(unsigned long long n, int bits) {
    for (int k = bits - 1; k >= 0; k--) {
        if ((n >> k) & 1)
            printf("1");
        else
            printf("0");
    }
}

typedef union {
    double d;
    struct {
        unsigned long long mantissa : 52;
        unsigned int exponent : 11;
        unsigned int sign : 1;
    } raw;
} mydouble;

void printIEEE(mydouble var) {
    printf("%d | ", var.raw.sign);
    printBinary(var.raw.exponent, 11);
    printf(" | ");
    printBinary(var.raw.mantissa, 52);
    printf("\n");
}

int main() {
    mydouble var;
    var.d = 1259.125;
    printf("IEEE 754 representation of %lf is:\n", var.d);
    printIEEE(var);
    return 0;
}

