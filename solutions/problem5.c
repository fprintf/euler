/*
 Problem 5 - Smallest Multiple

 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

NOTE: This solution is NOT optimal in any shape or form. This solution is a simple
brute force method. The optimal method is to simply multiply all the prime factors of
numbers 1 through 20 to get the result (which will also be produced by the output
of this program).
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool divisible(size_t num)
{
    double res;
    size_t i;

    for (i = 1; i <= 20; ++i) {
        res = num/(double)i;
        
        if (res != (size_t)res) {
        //    fprintf(stderr, "%zu is indivisible by %zu\n", num, i);
            return false;
        }
    }

    return true;
}

int main(int argc, char ** argv)
{
    size_t i;

    for (i = 20; /* empty */; i+=2) { /* Skip odd numbers obviously */
        if (divisible(i)) {
            printf("Found number: %zu\n", i);
            size_t found = i;
            for (i = 1; i <= 20; ++i)
                printf("\t%zu / %02zu = %lf\n", found, i, found/(double)i);

            break;
        }
    }

	return 0;
}
