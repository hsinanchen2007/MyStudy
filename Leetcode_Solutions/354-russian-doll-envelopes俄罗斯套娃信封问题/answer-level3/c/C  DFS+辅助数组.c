### 解题思路
此处撰写解题思路

### 代码

```c
int size;
int * dp;
int ** grid;
#define printf(fmt, args...) ((void)0)    //调试开关
int cmp(const void * a, const void * b){
    int *temp1 = *(int **)a;
    int *temp2 = *(int**)b;
    if(temp1[0]==temp2[0])return (temp1[1]- temp2[1]);
    return (temp1[0]-temp2[0]);

} 

int dfs(int i)
{   
    if(dp[i]!=-1)return dp[i]+1;
    int maxi=0;
    for(int j=i+1;j<size;j++)
    {
        //printf("%d: %d%d\n",i,grid[i][0],grid[i][1]);
        //printf("%d: %d%d\n",j,grid[j][0],grid[j][1]);
        if(grid[j][0]>grid[i][0]&&grid[j][1]>grid[i][1]){
            printf("from %d to %d！\n",i,j);
            int temp=dfs(j);
            printf("back %d to %d return %d!\n",j,i,temp);
            if(temp>maxi)
            {
                maxi=temp;
            }
        }
    }

    dp[i]=maxi;
    printf("dp[%d]=%d\n",i,dp[i]);
    return maxi+1;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    size=envelopesSize;
    grid=envelopes;
    int ans=0;

    dp=calloc(size,sizeof(int));
    for(int i=0;i<size;i++)
    {
        dp[i]=-1;
    }
    qsort(envelopes,size,sizeof(int*),cmp);
    for(int i=0;i<size;i++)
    {
        printf("%d %d\n",grid[i][0],grid[i][1]);
    }

    int max=0;
    for(int i=0; i<size;i++)
    {
        ans=dfs(i);
        if(ans>max)max=ans;
    }
    for(int i=0;i<size;i++)
    {
        printf("dp[%d]=%d ",i,dp[i]);
    }
    return max;

}
```