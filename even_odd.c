/*
 * even_odd.c
 */

#include <stdio.h>


// function main begins program execution
int main()
{
    int integer = 1;
    int odd_total = 0; // keeps value of index of the latest element and the number of total elements in odd array
    int even_total = 0; // keeps value of index of the latest element and the number of total elements  in even array
    int sum_even = 0;
    int sum_odd = 0;

    while(1){
        puts("Enter any interger or 0 for exit program:"); // prompt
        fflush( stdout ); // executes printf before scanf
        scanf("%d", &integer); // read an integer
        if (integer == 0){
            break;
        }
        if((integer % 2) == 0){
            puts("You entered even number.");
            even_total++;
            sum_even += integer;
        } else {
            puts("You entered odd number.");
            odd_total++;
            odd_total += integer;
        }
    }

    printf("Total number of even integers: %d\n", even_total);
    printf("Total number of odd integers: %d\n", odd_total);
    if(even_total == 0){
        puts("Program can not calculate the average of even numbers, because no even number entered.");
    } else {
        printf("The average value of the even integers: %d\n", sum_even/even_total);
    }

    if(odd_total == 0){
        puts("Program can not calculate the average of odd numbers, because no odd number entered.");
    } else {
        printf("The average value of the odd integers: %d\n", sum_odd/odd_total);
    }
} // end function main
