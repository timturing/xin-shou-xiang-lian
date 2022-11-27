#include <stdio.h>
#include<iostream>
using namespace std;
int a[55][55];//地图
int n,m;//图的长宽
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int resmax = -1;
// 辅助函数
int check_legal(int i,int j)
{
    if(i<0||i>=n)return 0;
    if(j<0||j>=m)return 0;
    return 1;
}
// 从[row,col]处出发能走的最大长度
int dg(int row,int col)
{
    //四个方向
    int tempmax=0;
    for(int i =0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            int newrow = row+dx[i];
            int newcol = col+dy[i];
            if(check_legal(newrow,newcol) && a[newrow][newcol]<=a[row][col])
            {
                int templen=dg(newrow,newcol);
                tempmax = tempmax>templen?tempmax:templen;
            }
        }
    }
    return tempmax+1;
}
int main()
{
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			int restemp = dg(i, j);
            // cout<<"i "<<i<<" j "<<j<<" res "<<restemp<<endl;
            resmax = resmax>restemp?resmax:restemp;
		}
	}
	printf("%d", resmax);
}
