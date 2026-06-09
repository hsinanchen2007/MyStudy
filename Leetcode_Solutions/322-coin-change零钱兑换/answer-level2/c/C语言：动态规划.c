有点像 leetcode 70 爬楼梯   f(n) = f(n - 1) + f(n - 2)

本题：动态转移方程
输入: coins = [1, 2, 5], amount = 11
opt(11) = min(opt(11 - 1), opt(11 - 2), opt(11 - 5)) + 1
类推：opt(amount) = min(opt(amount - coins[coinsSize])) + 1
```
int coinChange(int* coins, int coinsSize, int amount)
{
	int *dp = (int *)malloc(sizeof(int) * (amount + 1));
	for (int i = 0; i < amount + 1; i ++) {
        dp[i] = amount + 1;
    }
	dp[0] = 0;
	for (int i = 1; i <= amount; i++) {
		for (int j = 0; j < coinsSize; j++) {
			if (i >= coins[j]) {
				dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
			}
		}
	}
    int ret = dp[amount] > amount ? -1 : dp[amount]
    free(dp);
	return ret;
}
