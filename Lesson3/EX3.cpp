#include <stdio.h.>
#include <time.h>
#include <stdlib.h>

//1.Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.

void Convert(int number,char a[4])
{
    int result = 0;
    result = result + number % 2;
    
    if (number / 2 != 0)
    {
        Convert(number/2, a);
    }
    printf("%d",result);
}


//2.Реализовать функцию возведения числа[a] в степень[b]:
//a)Рекурсивно.

int Sqrtnumber(int a, int b)
{
    if (b > 1)
    {
        a = a * Sqrtnumber(a,b-1);
        
    }
    return a;
}


//b)Рекурсивно, используя свойство чётности степени(то есть, если степень, в которую нужно возвести число,
//  чётная, основание возводится в квадрат, а показатель делится на два, а если степень нечётная - результат умножается на основание,
//  а показатель уменьшается на единицу)

int SqrtnumberUsl(int a, int b)
{
    if (b > 1 && b % 2 == 0  )
    {
        a =  Sqrtnumber(a * a, b/2);

    }

    if (b > 1, b % 2 != 0)
    {
        a = a * Sqrtnumber(a, b - 1);
    }

    return a;
}

//c)Реализовать нахождение количества маршрутов шахматного короля с препятствиями(где единица - это наличие препятствия, а ноль - свободная
//для хода клетка)

//Версия первая не верная
void ShessKing()
{
    srand(time(NULL));
    int indexI = 1;
    int const a = 8;
    const unsigned char WHITE = 178;
    const unsigned char GRAY = 176;
    //случайная величина которая показывает на какой клетке появится король
    int king = 1 + rand()%(a*a);
    //Счетчик препятствий
    int walls = 0;
    
    char field[a*a];
    
   

    //i 1 - 64
    for (int i = 1; i <= a*a; i++)
    {
        int spot = 0 + rand() % 2;
        //Тут появляется шахматная доска
        if (indexI%2 != 0 )
        {

            if (i % 2 != 0 )
            {
                field[i - 1] = WHITE;
            }
            else
            {
                field[i - 1] = GRAY;
            }
        }
        else
        {
            if (i % 2 == 0 )
            {
                field[i - 1] = WHITE;
            }
            else
            {
                field[i - 1] = GRAY;
            }
        }

        if (i % a == 0)
        {

            indexI++;
        }
        //King и препятствия появляются тут

        if (spot == 0)
        {
            field[i - 1] = '&';
        }

        if (i == king)
        {

            field[i - 1] = 'K';
        }
       
    }
    //демонстрация поля с препятствиями и королем
    for (int i = 1; i <= a * a; i++)
    {
        printf("%c", field[i - 1]);

        if (i % a == 0)
        {
            printf("\n");
        }
    }

    //подсчет препятствий
    for (int j = 1; j <= a * a; j++)
    {
        if (j == king)
        {

            try 
            {
                if (field[j-2] == '&')
                {
                    walls++;
                }
            }
            catch (int i)
            {
                walls++;
            }
            try 
            {
                if (field[j - 10] == '&')
                {
                    walls++;
                }
            }
            catch (int i)
            {
                walls++;
            }
            try
            {
                if (field[j - 9] == '&')
                {
                    walls++;
                }
            }
            catch (int i)
            {
                walls++;
            }
            try
            {
                if (field[j - 8] == '&')
                {
                    walls++;
                }
            }
            catch (int i)
            {
                walls++;
            }
            try
            {
                if (field[j] == '&')
                {
                    walls++;
                }
            }
            catch (int i)
            {
                walls++;
            }
            try
            {
                if (field[j + 6] == '&')
                {
                    walls++;
                }
            }
            catch (int i)
            {
                walls++;
            }
            try
            {
                if (field[j + 7] == '&')
                {
                    walls++;
                }
            }
            catch (int i)
            {
                walls++;
            }
            try
            {
                if (field[j + 8] == '&')
                {
                    walls++;
                }
            }
            catch (int i)
            {
                walls++;
            }
        }
    }

    printf("Walls %d", walls);
}

void ShessKing2()
{
    srand(time(NULL));
    int indexI = 0;
    int const a = 8;
    const unsigned char WHITE = 178;
    const unsigned char GRAY = 176;
    //случайная величина которая показывает на какой клетке появится король
    int kingi = 0 + rand() % (a - 1);
    int kingj = 0 + rand() % (a - 1);
    int spot;

    //Счетчик препятствий
    int walls = 0;

    char field[a][a];

    for (int i = 0;i < a;i++)
    {
        for (int j = 0; j < a; j++)
        {
           spot = 0 + rand() % 5;
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    field[i][j] = WHITE;
                }
                else
                {
                    field[i][j] = GRAY;
                }
                
            }
            else
            {
                if (j % 2 != 0)
                {
                    field[i][j] = WHITE;
                }
                else
                {
                    field[i][j] = GRAY;
                }
            }

            
                field[kingi][kingj] = 'K';

                if (spot == 0)
                {
                    field[i][j] = '#';
                }
        }
    }

    

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("%c",field[i][j]);
        }
        printf("\n");
    }

    //подсчет препятствий
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            try
            {
                if (field[kingi+i][kingj+j] == '#')
                {
                    walls++;
                }

            }
            catch(int i)
            {
                walls++;
            }
        }
    }

    printf("\nNumber of Walls %d",walls);

}

int main()
{
    
    //setlocale(LC_ALL, "Rus");


    char a[4];
    printf("\n1.Recursive Decimal converter \n");
    Convert(10,a);

    /*int number;
    number = Convert(22);
    printf("\n1.Конвертер рекурсивный из десятичной \n%d ", number);*/

    printf("\n2.Recursive exponentiation \n%d", Sqrtnumber(2,4));
    printf("\n3.Recursive exponentiation with conditions \n%d\n\n\n", SqrtnumberUsl(10, 1));


    //printf("\n4.Шахматы\n%d", );
    printf("4.Shess\n\n");
    ShessKing2();

    return 0;
}

