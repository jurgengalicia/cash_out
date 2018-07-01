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

void checkearned(bills * money);
int assign(char * buf);
double total(bills * cash);
void init_bills(bills * money);
void print_bills(char * message, bills * money, int mode);
bills pull_out(bills * money);
void populate_bills();


