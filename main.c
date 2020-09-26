#include <stdio.h>
#include "unt.h"

int main(void)
{
    puts("This is a shared library test...");

    int mip;
    mip  =  bar();

    printf("mips + %d\n", mip);

    return 0;
}

