#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main()
{
    
    setlocale(LC_ALL, "Rus");
    printf("Привет, мир");
    _getch();

    return 0;
}

