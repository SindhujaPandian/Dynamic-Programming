#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dp[100][100];
int max(int n1,int n2)
{
    return (n1>n2)?n1:n2;
}
int print(int i,int j ,char str1[],char str2[])
{
    if(i==0 || j==0)
        return 0;
    else if(str1[i-1]==str2[j-1])
    {
        print(i-1,j-1,str1,str2);
        printf("%c",str1[i-1]);
    }
    else if(dp[i][j-1]>=dp[i-1][j])
    {
        print(i,j-1,str1,str2);
    }
   else
        print(i-1,j,str1,str2);
}
int main()
{
    char str1[100],str2[100],n,m;
    printf("Enter the string 1 : ");
    scanf("%s",str1);
    printf("Enter the string 2 : ");
    scanf("%s",str2);
    n = strlen(str1);
    m = strlen(str2);

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    for(int i=0;i<=n;i++,printf("\n"))
    {
        for(int j=0;j<=m;j++)
            printf("%d\t",dp[i][j]);
    }
    printf("\nThe Length of the longest common subsequence is %d ",dp[n][m]);
    print(n,m,str1,str2 );
    return 0;
}
