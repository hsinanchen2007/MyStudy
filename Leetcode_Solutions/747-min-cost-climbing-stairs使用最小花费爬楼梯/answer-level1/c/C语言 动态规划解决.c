### 解题思路
思路：动态规划。
dp[i]记录的是到达第i层需要的最少cost，由于一次可以上1层或者上2层，所以dp[i]的值取决于前两层的cost。
得到递推式：dp[i] = min((dp[i-1] + cost[i-1]) , (dp[i-2] + cost[i-2]))
根据题意，达到最后一层即dp[costSize]，故初始化数组大小为costSize+1。判断数组大小去除特殊情况。

### 代码

```c
int minCostClimbingStairs(int* cost, int costSize){
    if(costSize == 1)return cost[0];
    if(costSize == 2)return (cost[0]>cost[1])?cost[1]:cost[0];
    int dp[costSize+1];
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i<costSize + 1; i++){
        dp[i] = ((dp[i-1] + cost[i-1]) < (dp[i-2] + cost[i-2]))?(dp[i-1] + cost[i-1]):(dp[i-2] + cost[i-2]);
    }
    return dp[costSize];
}
```