/*
 Problem 1 - 3 and 5

 Print the sum of all multiples of 3 and 5 under 1000
*/
#include <stdio.h>

#define MAX 1000L

int main(void)
{
    size_t sum = 0;
    size_t bythree, byfive;

    for (bythree = 3, byfive = 5; bythree < MAX; bythree += 3, byfive += 5) {
        /* Only add byfive if it's not one we'd add anyway */
        if (byfive % 3 && byfive < MAX)
            sum += byfive;
        sum += bythree;
    }

    printf("Sum of all multiples of 3 and 5 below %ld: %zu\n", MAX, sum);

    return 0;
}
