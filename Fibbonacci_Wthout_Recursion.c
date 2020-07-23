#include <stdio.h>
#include <stdlib.h>
void fibonacci(int n)
{
    int num1=0,num2=1,sum=0;
    printf("%d\n",num2);
    for(int i=1;i<n;i++)
    {
        sum=num1+num2;
        printf("%d\n",sum);
        num1=num2;
        num2=sum;

    }

}

int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    fibonacci(n);
    return 0;
}
