#include <stdio.h>
int main()
{
	char right='A';
	int flag=0;
	int n;
	char m;
	scanf("%d",&n);
	for(right='A';right<='H';right++)
	{
		int sum=0;
		if(right=='H'||right=='F')
		sum=sum+2;
		if(right=='B')
		sum++;
		if(right=='G')
		sum++;
		if(right!='B')
		sum++;
		if(right!='H'&&right!='F');
		sum=sum+2;
		if(right!='C')
		sum++;
		if(sum==n)
		{
			flag++;
			m=right;
		}

	}
		if(flag==0||flag>1)
		printf("DONTKNOW");
		else
		printf("%c",m);
	
}
