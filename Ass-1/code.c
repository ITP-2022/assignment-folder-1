#include <stdio.h>
#include <math.h>
#include <stdbool.h> 
int main()
{
    int b;  // b stores size of array
    bool perfect = false; //this will tell whether there is any perfect number or not
    int a[100];
    printf("Enter number of elements:");
    scanf("%d", &b);
    printf("Enter elements---->");
    for (int i = 0; i < b; i++)  //this loop will take input of the array
    {
        scanf("%d", &a[i]);
    }
    int sum = 0, d = 0;   //sum will store sum of divisors of array input and d will store sum of all perfect numbers
    for (int i = 0; i < b; i++) // To extract the value from array like a[i]
    {
        sum = 0;
        for (int j = 1; j <= a[i] / 2; j++) //loop will check perfect number
        {
            if (a[i] % j == 0)
            {
                sum = sum + j; // sum of divisors like 1+2+3=6
            }
        }
        if (sum == a[i]){          
            printf("%d  is a perfect number\n", sum);
            d = d + sum;
            perfect = true;
        }
    }
    if(perfect == true){
        printf("%d  is the sum of the perfect numbers\n", d);
        int sum1 = d, digsum = 0, nod = 0;  // sum1 will make copy of d(sum of perfect numbers) and digsum stores sum of power(cube) of digits of number and nod stores number of digits 
        while (sum1 != 0){   // this loop will check number of digits
            nod++;                 
            sum1 = sum1 / 10;
        }
        int sum2 = d;  // sum2 is copy of d(sum of perfect numbers)
        while (sum2 != 0) //this loop will check for armstrong number 
        {
            int e = sum2 % 10;    
            digsum = digsum + pow(e, nod);
            sum2 = sum2 / 10;
        }
        if (digsum == d){
            printf("%d is an Armstrong Number", d);
        }
        else {
            printf("%d is not an Armstrong Number", d);
        }
    }
    else
    {
        printf("There is no perfect number");
    }
    return 0;
}