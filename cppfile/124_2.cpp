#include <stdio.h>
int count = 0;
int a[55][55];
int go[55][5] = {0};
int max = -10000;
void dg(int line, int list, int n, int m)
{

	for (int i = 0; i < 4; i++) //四个选择的循环
	{
		if (line + 1 <= n - 1 && i == 0 && a[line][list] > a[line + 1][list])
		{

			count = count + 1;
			dg(line + 1, list, n, m);
			count = count - 1; //回溯
		}
		else if (list + 1 <= m - 1 && i == 1 && a[line][list] > a[line][list + 1])
		{
			count = count + 1;
			dg(line, list + 1, n, m);
			count = count - 1;
		}
		else if (list - 1 >= 0 && i == 2 && a[line][list] > a[line][list - 1])
		{
			count = count + 1;
			dg(line, list - 1, n, m);
			count = count - 1;
		}
		else if (line - 1 >= 0 && i == 3 && a[line][list] > a[line - 1][list])
		{
			count = count + 1;
			dg(line - 1, list, n, m);
			count = count - 1;
		}
	}
	
	if ((line + 1 == n || a[line][list] < a[line + 1][list]) && (line == 0 || a[line][list] < a[line - 1][list]) && (list == 0 || a[line][list] < a[line][list - 1]) && (list + 1 == n || a[line][list] < a[line][list + 1]))
	{
		if (count > max)
			max = count;
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			dg(i, j, n, m);
		}
	}
	printf("%d", max + 1);
}
