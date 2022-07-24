/*
 *   File:       main.c
 *
 *   Contains:   cexception test
 *
 *   Written by: GuEe-GUI
 *
 *   Copyright:  (C) 2017-2022 by GuEe Studio. All rights reserved.
 *
 *   License:    Apache-2.0
 */

#include <stdio.h>

#include "cexception.h"

int main(int argc, char *argv[])
{
    try
    {
        try
        {
            throw(0);
        }
        catch(x)
        {
            printf("Inner: %d\n", x);
            throw(x + 1);
        }
    }
    catch(x)
    {
        printf("Outter: %d\n", x);
    }

    return 0;
}
