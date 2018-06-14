#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 0; // this is for printing hashes
    int j = 0; // this is for printing empty spaces
    int height;
    int spaces; // this is for the spaces that make the pyramid right to left

    // this is accepting user input, a do while for checking as well
    do
    {
        printf("Insert a number between 0-23: ");
        height = get_int();
    }
    while (height < 0 || height > 23);

    // height = 8, you want a spaces variable just to keep track of spaces
    spaces = height;

    /*
    0123456# 1  7 spaces
    012345## 2  6 spaces
    01234### 3  5 spaces
    0123#### 4  .
    012##### 5  .
    01###### 6  .
    0####### 7  .
    ######## 8  0 spaces
    */

    // this is a loop for the actual pyramid itself
    for (int num = 0; num < height; num++) // this is the loop based on height
    {
        for (j = 0 ; j < spaces - 1; j++) // loop for spaces
        {
            printf(" ");
        }
        spaces--; // just so you don't mess with the height, spaces is changed every time we iterate
        for (i = 0; i < num + 1; i++) // this is the hash loop, based on the height
        {
            printf("#");
        }
        printf("  "); // gap is 2 spaces
        for (i = 0 ; i < num + 1; i++) // repeat for the other side
        {
            printf("#");
        }
        printf("\n");
    }
}
