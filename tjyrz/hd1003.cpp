#include<iostream>
using namespace std;
int main()
{
	
	int t,sum,max,n;
	int a[100000];
	int as,ae;
	int start,end;
	
	cin>>t;
	sum=-9999;
	max=-9999;
	for (int l=0;l<t;l++)
	{
		sum=-9999;
		max=-9999;
		as=0;ae=0;
		start=0;end=0;
		cin>>n;
		for (int i=0;i<n;i++)
		{	
			cin>>a[i];
		}
		for (int i=0;i<n;i++)
		{
			if (sum<0)
			{
				if (sum<a[i])
				{
					sum=a[i];
					as=i;ae=i;
					if (max<sum)
					{
						max=sum;
						start=as;
						end=ae;
					}
				}
			}
			else 
			{
				sum+=a[i];
				ae=i;
				if (max<sum)
				{
					max=sum;
					start=as;
					end=ae;
				}
			}
		}
		cout<<"Case "<<l+1<<":"<<endl;
		cout<<max<<" "<<start+1<<" "<<end+1<<endl;
		if (l!=t-1)
		cout<<endl;
}
	return 0;
}