#include<stdio.h>
#include<limits.h>

int MatrixChainOrder(int p[], int n)
{

   int m[n][n];
   int i, j, k, L, q;
   for (i=1; i<n; i++)
        m[i][i] = 0;

   for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;

                    printf("\nm[i][k] =%d , m[k+1][j] =%d, p[i-1]=%d, p[k],= %d , p[j] = %d , i=%d, j=%d, k=%d\n",m[i][k],m[k+1][j],p[i-1],p[k],p[j],i,j,k);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%10d\t\t\t",m[i][j]);
        printf("\n");
    }
    return m[1][n-1];
}

int main()
{
    int size;
    printf("Enter the size of the array :  ");
    scanf("%d",&size);
    int arr[size];
    printf("\n\nEnter the array elements \n");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);

    printf("Minimum number of multiplications is %d ",
                       MatrixChainOrder(arr, size));

    getchar();
    return 0;
}
