```c
int sum;
const int ways[2][2]={{1,0},{0,1}};//方向

int get(int a,int b)//求数位和
{
    int ans=0;
    while(a!=0)
    {
        ans+=a%10;
        a/=10;
    }
    while(b!=0)
    {
        ans+=b%10;
        b/=10;
    }
    return ans;
}
void dfs(int x,int y,int k,int m,int n,int *save)
{
if(get(x,y)>k)
    return;
else
{
    save[x*n+y]=1;
    sum++;
}
for(int i=0;i<2;i++)
    {
        if(x+ways[i][0]<m&&y+ways[i][1]<n&&save[(x+ways[i][0])*n+y+ways[i][1]]==0)
            dfs(x+ways[i][0],y+ways[i][1],k,m,n,save);
    }
}
int movingCount(int m, int n, int k){
    if(!k)
        return 1;
    int *save=calloc(m*n,sizeof(int));//去重数组
    sum=0;//全局变量的初始化！
    dfs(0,0,k,m,n,save);
    return sum;
}
```
