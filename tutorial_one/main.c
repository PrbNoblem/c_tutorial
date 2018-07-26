#include <stdio.h>



int main()
{
    /*Remember to decalre variables first!*/
    int number;

    printf("This is C program hello.\nPlease enter a number\n");
    scanf("%d", &number);
    /*
    
    if (66)
    {
        printf("66 was true!\n");
    }
    if (number == 1488)
    {
        printf("Heil Hitler!\n");   
    }
    else
    {
        printf("You entered %d\n", number);    
    }
    */
    do {
        printf("Number was %d, unacceptable!\n", number);
        scanf("%d", &number);
    } while (number != 1488);
    getchar();
    printf("bye\n");
    return 0;
}