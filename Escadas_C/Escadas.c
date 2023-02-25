#include <stdio.h>

int subindoEscadas(int numero)
{
    int a, b = 1, c = 1;
    for (int i = 0; i < numero; i++)
    {
        a = b + c;
        c = b;
        b = a;
    }
}

int main(){
    subindoEscadas(2);
}