/*
 * even_odd.c
 */

#include <stdio.h>

void goldbach(int n);
int isPrime(int n);
int canBeRepresentedAsSumOfTwoPrimes(int n);
int main()
{
    int isFirstNumber = 1;
    int firstNum;
    int odd_total = 0, even_total = 0;
    int sum_even = 0, sum_odd = 0;
    int enteredInteger;

    while(1){
        puts("Enter any interger or 0 for exit program:"); // prompt
        fflush( stdout ); // executes printf before scanf
        scanf("%d", &enteredInteger); // read an enteredInteger

        if(isFirstNumber){ // saves only the first number
            firstNum = enteredInteger;
            isFirstNumber--;
        }

        if (enteredInteger == 0){
            break;
        }

        if((enteredInteger % 2) == 0){
            puts("You entered even number.");
            even_total++;
            sum_even += enteredInteger;
        } else {
            puts("You entered odd number.");
            odd_total++;
            odd_total += enteredInteger;
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

    if(firstNum != 0){
        printf("Printing goldbach:\n");
        goldbach(firstNum);
    } else {
        printf("Cannot compute goldbach\n");
    }
}

void goldbach(int n){
    for( ; n > 0; n--){
        if(canBeRepresentedAsSumOfTwoPrimes(n) == 0){
            printf("%d\n", n);
        }
    }
}

int canBeRepresentedAsSumOfTwoPrimes(int n){
    for(int i = 2; i <= n/2; i++){ // start functioning from n = 4, because 1, 2, 3 cannot be represented as the sum of two primes. 4 can , because  2+2 are primes
        if(isPrime(i) == 1){ // for all prime numbers less than half of number.
            if(isPrime(n-i) == 1){
                return 1;
            }
        }
    }
    return 0;
}
int isPrime(int n){
    for(int i = 2; i <= n/2; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

