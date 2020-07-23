/*
To find the Nth Fibonacci Number
*/
#include <stdio.h>
#include <stdlib.h>
int fibonacci(int n)
{
    if(n<=1)
        return n;
    else
        return fibonacci(n-1)+fibonacci(n-2);

}

int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            printf("%d\n",fibonacci(i));
    }

    return 0;
}
