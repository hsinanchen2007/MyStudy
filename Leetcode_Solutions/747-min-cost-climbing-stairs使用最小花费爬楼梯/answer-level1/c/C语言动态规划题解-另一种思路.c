
## 思路：
因为第 i 个位置可以从 第 i - 2 位置跳过来，也可以从 i - 1 位置跳过来
**状态转移方程**
*dp[i] = Min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1])*

## 初始状态
第0个位置和第1个位置都可以直达，所以dp[0] = dp[1] = 0


```
#define MAX_SIZE 1001

int Min(int a, int b)
{
    return a > b ? b : a;
}

int minCostClimbingStairs(int* cost, int costSize){
    
    
    // 第 i 个位置可以从 第 i - 2 位置跳过来，也可以从 i - 1 位置跳过来
    // 所以 dp[i] = Min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1])
    // dp[0] = 0, dp[1] = 0 因为这两个位置都可以直达
    
    int dp[MAX_SIZE] = {0};
    
    
    dp[0] = 0;
    
    dp[1] = 0;
    
    for (int i = 2; i <= costSize; i++) {
        dp[i] = Min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    
    return dp[costSize];

}
```
