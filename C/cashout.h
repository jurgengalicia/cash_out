#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int hundred;
    int fifty;
    int twenty;
    int ten;
    int five;
    int two;
    int one;
    int quarter;
    int dime;
    int nickel;
    int penny;
    int leave;
    double total;
    double earned;
} bills;

void populate_bills();
int assign(char * buf);
void checkearned(bills * money);




