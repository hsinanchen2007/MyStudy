### 解题思路
经典的完全背包问题，讲解参考链接：https://zhuanlan.zhihu.com/p/93857890

### 代码

```c
int coinChange(int* coins, int coinsSize, int amount)
{
    if (coins == NULL) {
		return -1;
	}
	
	int *dp = (int*)malloc(sizeof(int) * (amount + 1));
	if (dp == NULL) {
		return -1;
	}
	dp[0] = 0;
	for (int i = 1; i <= amount; i++) {
		dp[i] = INT_MAX;
	}
	
	for(int i = 1; i <= coinsSize; i++) {
        for(int j = coins[i-1]; j <= amount; j++){
            // 下行代码会在 1+INT_MAX 时溢出
            // dp[j] = min(dp[j], 1 + dp[j - coins[i-1]]); 
            if(dp[j] - 1 > dp[j - coins[i-1]])
                dp[j] = 1 + dp[j - coins[i-1]];   
        }
	}
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}
```