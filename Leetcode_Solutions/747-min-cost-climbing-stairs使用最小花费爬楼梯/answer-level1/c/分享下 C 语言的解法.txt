### 解题思路


### 代码

```c
int min(int a,int b){return a<b?a:b;}
int minCostClimbingStairs(int* cost, int m){
    int *dp = (int *)malloc(m*sizeof(int));
    // 考虑特殊情况
    if(m<=0) return 0;
    if(m==1) return cost[0];
    if(m==2) return min(cost[0],cost[1]);

    dp[0]=cost[0];
    dp[1]=cost[1];

    for (int i = 2; i < m; ++i)
    {
    	dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
    }
    return min(dp[m-1],dp[m-2]);
}
	
```