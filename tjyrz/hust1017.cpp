#include<cstdio>
#define N 2011
#define M 102011
int U[M],D[M],L[M],R[M],C[M],X[M];
int H[N],S[N],Q[N];
int size,n,m;
void remove(int c)
{
    R[L[c]]=R[c],L[R[c]]=L[c];
    for(int i=D[c]; i!=c; i=D[i])
        for(int j=R[i]; j!=i; j=R[j])
            U[D[j]]=U[j],D[U[j]]=D[j],--S[C[j]];
}
void resume(int c)
{
    R[L[c]]=L[R[c]]=c;
    for(int i=U[c]; i!=c; i=U[i])
        for(int j=L[i]; j!=i; j=L[j])
            ++S[C[U[D[j]]=D[U[j]]=j]];
}
bool Dance(int k)
{
    int i,j,tmp,c;
    if(!R[0])
    {
        printf("%d",k);
        for(i=0; i<k; ++i)printf(" %d",X[Q[i]]);
        puts("");
        return 1;
    }
    for(tmp=N,i=R[0]; i; i=R[i])
        if(S[i]<tmp)tmp=S[c=i];
    remove(c);
    for(i=D[c]; i!=c; i=D[i])
    {
        Q[k]=i;
        for(j=R[i]; j!=i; j=R[j])remove(C[j]);
        if(Dance(k+1))return 1;
        for(j=L[i]; j!=i; j=L[j])resume(C[j]);
    }
    resume(c);
    return 0;
}
void Link(int r,int c)
{
    ++S[C[size]=c];
    D[size]=D[c];
	U[size]=c;
    U[D[c]]=size;
    D[c]=size;
    if(H[r]<0)H[r]=L[size]=R[size]=size;
    else
    {
        R[size]=R[H[r]];
        L[R[H[r]]]=size;
        L[size]=H[r];
        R[H[r]]=size;
    }
    X[size++]=r;
}
int main()
{
    int i,j,num;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0; i<=m; ++i)
        {
            S[i]=0;
            D[i]=U[i]=i;
            L[i+1]=i;
            R[i]=i+1;
        }
        R[m]=0;
        size=m+1;
        for(i=1; i<=n; ++i)
        {
            H[i]=-1;
            scanf("%d",&num);
            while(num--)scanf("%d",&j),Link(i,j);
        }
        if(!Dance(0))puts("NO");
    }
    return 0;
}
