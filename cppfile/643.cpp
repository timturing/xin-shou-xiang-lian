#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[10];
int k;
int main()
{
    scanf("%s",a);
    scanf("%d",&k);
    int len = strlen(a);
    for(int i=0;i<len;i++)
    {
        if(a[i]=='X')
        {
            int cnt= 0;
            int j=0;
            if(i==0)j=1;
            for(;j<=9;j++)
            {
                a[i]='0'+j;
                int N = atoi(a);
                // printf("%d\n",N);
                if(N%k==0)cnt++;
            }
            printf("%d",cnt);
            // break;
            return 0;
        }
    }
}