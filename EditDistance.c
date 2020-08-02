#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int min(int x, int y, int z) // min (up,left,right)
{
    if(x<y)
        if(x<z)
            return x;
        else
            return z;
    else
        if(y<z)
            return y;
        else
            return z;
}

int main()
{
    char str1[100], str2[100];
    int m,n;
    printf("Enter the First string :  ");
    scanf("%s",str1);
    printf("\nEnter the second string :  ");
    scanf("%s",str2);
    m = strlen(str1);
    n = strlen(str2);
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j],dp[i - 1][j - 1]);
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("\n\n The minimum distance is %d",dp[m][n]);
    return 0;
}
