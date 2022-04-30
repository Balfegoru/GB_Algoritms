#include <stdio.h>


void NumberSimple(int number)
{
   
    for (int i = 2; i < number; i ++ )
    {
        
        if (number % i == 0)
        {
            printf("Not Simple Number");
            return;
        }
    }

    printf("Simple Number");

}


int main()
{

    NumberSimple(10);

    return 0;
}

