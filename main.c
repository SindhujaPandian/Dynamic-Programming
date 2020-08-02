#include <stdio.h>
#include <stdlib.h>
int max(int x, int y, int z)
{
if(x>y)
    if(x>z)
        return x;
    else
        return z;
else
    if(y>z)
        return y;
    else
        return z;
}
int main()
{
    int n;
    scanf("%d",&n);
    int val[n+1];
   val[0] = val[1] = 0;
   for (int i = 1; i <= n; i++)
   {
      int max_val = 0;
      for (int j = 1; j <= i/2; j++)
         max_val = max(max_val, (i-j)*j, j*val[i-j]);
      val[i] = max_val;
   }
   printf("%d",val[n]);
   printf("\nThe Array value is \n");
   for(int i=0;i<=n;i++)
    printf("%d\n",val[i]);
    return 0;
}
