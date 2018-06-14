#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    /*
        prompt user for an amount of change
         - get_float
        always use the largest coin possible
        keep track of coins used
        print the final number of coins
    */
    float val;
    int valInt; //to make a whole value
    int quarter = 25;
    int quarter_used = 0;
    int dime = 10;
    int dime_used = 0;
    int nickel = 5;
    int nickel_used = 0;
    int penny = 1;
    int penny_used = 0;
    int remainder;
    int coinSum = 0;

    //Asking user for input
    do
    {
        printf("Change owed: ");
        val = get_float();
    }
    while (val < 0);

    //making val a whole number/integer
    valInt = round(val * 100);



    //printf("%f\n",val);
    //printf("%i\n",valInt);
    //printf("%i\n", valInt%quarter);


    //ordinary way
    /*
    for (int i=0; i < valInt; i++){
        if (quarter <= valInt){
            valInt-=quarter;
            quarter_used++;
        }
        else if (dime <= valInt){
            valInt-=dime;
            dime_used++;
        }
        else if (nickel <= valInt){
            valInt-=nickel;
            nickel_used++;
        }
        else if (penny <= valInt){
            valInt-=penny;
            penny_used++;
        }
        printf("%d\n",valInt/100);

    }
    */

    //Modular

    if (valInt % quarter >= 0) //yes quarters can go in
    {
        remainder = valInt % quarter;
        quarter_used = valInt / quarter;
        if (remainder % dime >= 0) //yes dimes can go in
        {
            dime_used = remainder / dime;
            remainder = remainder % dime;
            if (remainder % nickel >= 0) //yes nickels can go in
            {
                nickel_used = remainder / nickel;
                remainder = remainder % nickel;
                if (remainder % penny >= 0) //yes pennies can go in
                {
                    penny_used = remainder / penny;
                    remainder = remainder % penny;
                }
            }
        }

    }




    //printf("Quarters Used: %i\n", quarter_used);
    //printf("Dimes Used: %i\n", dime_used);
    //printf("Nickels used: %i\n", nickel_used);
    //printf("Pennies Used: %i\n", penny_used);
    coinSum = quarter_used + dime_used + nickel_used + penny_used;
    printf("%i\n", coinSum);
}
