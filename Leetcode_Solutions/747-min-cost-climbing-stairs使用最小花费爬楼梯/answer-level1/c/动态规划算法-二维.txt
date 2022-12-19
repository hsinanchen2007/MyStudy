```
#define min(a,b) (a)<(b)?(a):(b)
int minCostClimbingStairs(int* cost, int costSize)
{
    if(cost == NULL || costSize < 2 || costSize > 1000)return 0;
    int dp[costSize][2]; //定义DP值为最小的cost值；
    dp[0][0] = 0;
    dp[0][1] = cost[0];
    dp[1][0] = cost[0];
    dp[1][1] = cost[1];
    for(int i=2;i<costSize;i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][0]+cost[i],dp[i-1][1]+cost[i]);
    }
    return min(dp[costSize-1][0],dp[costSize-1][1]);
}
```
