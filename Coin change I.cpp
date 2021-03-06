int uncoin(int coin[],int n,int s)
{
    int t[n+1][s+1];
    memset(t,-1,sizeof(t));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<s+1;j++)
        {
            if(i==0)
            {
                t[i][j]=0;
            }
            if(j==0)
            {
                t[i][j]=1;
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<s+1;j++)
        {
            if(coin[i-1]<=j)
            {
                t[i][j]=(t[i][j-coin[i-1]]+t[i-1][j]);
            }
            else 
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][s];
}

int main()
{
    int coin[]={1,2,3};
    int n=sizeof(coin)/sizeof(coin[0]);
    int s=5;
    cout<<uncoin(coin,n,s);
}
