### 解题思路
动态规划法，与70题跳台阶的算法基本相同。
dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])

### 代码

```c
#define MIN(x,y) (x<y)?x:y
int minCostClimbingStairs(int* cost, int costSize){
    int i,j;
    int sum1,sum2;
    int* dp=(int*) malloc((costSize+1)*sizeof(int));
    dp[0]=0;
    dp[1]=0;
    for(i=2;i<=costSize;i++){
        dp[i]=MIN(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
    }
    return dp[costSize];
}
```