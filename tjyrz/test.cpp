#include <stdio.h>
int main()
{
	int i=2;
	int x = (++i) + (++i) + (++i);
	int j=2;
	printf("x = %d\n %d",x,((++j) + (++j) + (++j)));
	scanf("%d",&x);
	return 0;
}