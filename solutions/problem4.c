/*
 Problem 4 - Largest palindrome product

   A palindromic number reads the same both ways.  The largest palindrome made from 
 the product of two 2-digit numbers is 9009 = 91 × 99.  Find the largest palindrome
 made from the product of two 3-digit numbers.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h> 

bool ispalindrome(size_t number)
{
    char s[BUFSIZ];
    size_t bytes = snprintf(s,BUFSIZ,"%zu",number);

    if (bytes <= 0 || bytes >= BUFSIZ) {
        fprintf(stderr, "Failed to check %zu exceeds length of string\n", number);
        return false;
    }

    /* Check if the string is the same forwards and backwards */
    char * start = s;
    char * end = s + strlen(s) - 1;

    while (start < end) {
        if (*start++ != *end--)
            return false;
    }

    return true;
}

int main(int argc, char ** argv)
{
    size_t num1, num2;
    size_t best = 0;

    for (num1 = 999; num1 >= 100; --num1)
        for (num2 = 999; num2 >= 100; --num2) {
            size_t product = num1 * num2;
            if (ispalindrome(product) && product > best) {
                best = product;
            }
        }

    printf("Found palindromic product: %zu\n", best);
            

	return 0;
}
