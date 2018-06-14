#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /*
        Prompt user for input (almost)
        Multiply every other digit (done)
        Sum those digits (done)
        add to remaining digits (done)
        validate checksum (done)
        validate company's identifier (done)
        validate number length (done)
    */

    long creditOriginal = 0;
    int flag = 'n';
    int lengthCheck(long creditNumber);
    char cardCheck(long creditNumber);

    printf("Number: ");
    creditOriginal = get_long_long();
    flag = cardCheck(creditOriginal);
    do
    {
        if (flag != 'y')
        {
            //printf("This is an invalid card.\n");
            printf("Number: ");
            creditOriginal = get_long_long();
            flag = cardCheck(creditOriginal);
        }
    }
    while (flag == 'n');
}


int lengthCheck(long creditNumber) // Does as the name asks for, checks for the length of of the credit card number specified
{
    int length = 0;
    while (creditNumber > 0)
    {
        creditNumber /= 10;
        length++;
    }
    return length;
}

char getFirstTwoDigits(long creditNumber, int length) //gets the first two digits and checks for what the two digits are
{
    //returns a character for the kind of card it is
    char identifier = 'n';
    int sum = 0;
    /*
        Amex = a
            - 15
            - start with 34 and 37
        MasterCard = m
            - 16
            - start with 51, 52, 53, 54, 55
        Visa
            - 13 and 16
            - start with 4
    */

    switch (length)
    {
        case 13: //visa case
            for (int i = 0; i < length; i++) //go through whole loop, but then when i=11, 12 keep track of a sum
            {
                if (i == 12)
                {
                    sum += (creditNumber % 10);
                }
                creditNumber /= 10;
            }
            if (sum == 4)
            {
                identifier = 'v';
            }
            break;
        case 15://amex case
            for (int i = 0; i < length; i++) //go through whole loop, but then when i=11, 12 keep track of a sum
            {
                if (i == 14 || i == 13)
                {
                    sum += (creditNumber % 10);
                }
                creditNumber /= 10;
            }
            if (sum == 7 || sum == 10)
            {
                identifier = 'a';
            }
            break;
        case 16://visa and other case
            for (int i = 0; i < length; i++) //go through whole loop, but then when i=11, 12 keep track of a sum
            {
                if (i == 15 || i == 14)
                {
                    if (i == 15)
                    {
                        //checks for the visa case when it comes to 16 digits
                        if ((creditNumber % 10) == 4)
                        {
                            identifier = 'v';
                            break;
                        }
                    }
                    sum += (creditNumber % 10);
                }
                creditNumber /= 10;
            }
            if (sum == 6 || sum == 7 || sum == 8 || sum == 9 || sum == 10)
            {
                identifier = 'm';
            }
            break;
    }
    return identifier;
}

char cardCheck(long creditNumber)
{
    //originally named authorization = this is for the checking the whole card
    // incorporates
    long credit = 0;
    long creditOriginal = 0;
    int multSum = 0;
    int mult = 0;
    int checksum = 0;
    int sum = 0;
    char flag = 'n';

    creditOriginal = creditNumber;
    credit = creditOriginal;
    // This is the multiplication route
    for (int i = 0; i < lengthCheck(creditOriginal); i++)
    {
        if (i % 2 == 1)
        {
            mult = (credit % 10) * 2;
            if (mult >= 10)
            {
                for (int j = 0; j < 2; j++)
                {
                    multSum += mult % 10;
                    mult /= 10;
                }
            }
            multSum += mult;
        }
        credit /= 10;
    }

    creditOriginal = creditNumber;
    credit = creditOriginal;
    //printf("creditOriginal = %li", creditOriginal);
    for (int k = 0; k < lengthCheck(creditOriginal); k++)
    {
        if (k % 2 == 0)
        {
            sum += credit % 10;
        }
        credit /= 10;
    }

    checksum = sum + multSum;
    if (checksum % 10 == 0)
    {
        //printf("This card is valid\n");
        if (getFirstTwoDigits(creditNumber, lengthCheck(creditNumber)) == 'a')
        {
            printf("AMEX\n");
        }
        if (getFirstTwoDigits(creditNumber, lengthCheck(creditNumber)) == 'v')
        {
            printf("VISA\n");
        }
        if (getFirstTwoDigits(creditNumber, lengthCheck(creditNumber)) == 'm')
        {
            printf("MASTERCARD\n");
        }
        flag = 'y';
        if (getFirstTwoDigits(creditNumber, lengthCheck(creditNumber)) == 'n')
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
        flag = 'y';
    }
    //printf("flag = %c\n", flag);
    return flag;
}

// 378282246310005
// 3782822463100

// 36942143843081 invalid
// 369421438430814 invalid
// 4062901840 invalid
// 5673598276138003 invalid
