### 解题思路
dp数组是一年中的每一天，转移方程代码应该很清楚
![捕获.PNG](https://pic.leetcode-cn.com/dcee6609665a84517761ec6ed3d95678e6a5432778c5f32a0db565ec7688896f-%E6%8D%95%E8%8E%B7.PNG)
### 代码

```c
int mincostTickets(int* days, int daysSize, int* costs, int costsSize){
    int dp[366]={0};
    int hash[366]={0};
    for(int i=0;i<daysSize;i++)
        hash[days[i]]=1;
    for(int i=1;i<=365;i++)
    {
        if(hash[i]==1)
        {
            dp[i]=dp[i-1]+costs[0];
            dp[i]=dp[i]<(dp[(i>=7?(i-7):0)]+costs[1])?dp[i]:(dp[(i>=7?(i-7):0)]+costs[1]);
            dp[i]=dp[i]<(dp[(i>=30?(i-30):0)]+costs[2])?dp[i]:(dp[(i>=30?(i-30):0)]+costs[2]);
        }
        else
            dp[i]=dp[i-1];
    }
    return dp[days[daysSize-1]];
}
```