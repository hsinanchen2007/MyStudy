```
int minCostClimbingStairs(int* cost, int costSize){
    int i;
    int* dp = (int*)malloc(sizeof(int) * (costSize + 1));

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(i = 2; i < costSize; i++) {
        dp[i] = fmin(dp[i - 1], dp[i - 2]) + cost[i];
    }
    dp[costSize] = fmin(dp[costSize - 1], dp[costSize - 2]);
    return dp[costSize];
}
```
