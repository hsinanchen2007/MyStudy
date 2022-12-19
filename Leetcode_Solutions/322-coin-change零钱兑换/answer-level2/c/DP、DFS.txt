### 解题思路
- 非常经典的题目，两种做法，自顶向下，自底向上；
- 两者相比较，动态规划好理解一些，不过仁者见仁智者见智
- 值得注意的是，一维DP区间模型，套路写法
```
	for (k = 0; k < coinsSize; k++) {
		if (amount < coins[k]) {
			continue;
		}
		subAns = Dfs(coins, coinsSize, amount - coins[k]);
		if (subAns != -1) {
			tmp = MIN(tmp, subAns);
		}
	}
	if (tmp == INT_MAX) {
		return g_mem[amount] = -1;
	}
```


### 代码
【自顶向下 - 递归】
```c
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static int *g_mem;

static int Dfs(int* coins, int coinsSize, int amount)
{
	int k, tmp, subAns;

	if (amount == 0) {
		return 0;
	}
	if (g_mem[amount] != INT_MAX) {
		return g_mem[amount];
	}
	tmp = INT_MAX;
	for (k = 0; k < coinsSize; k++) {
		if (amount < coins[k]) {
			continue;
		}
		subAns = Dfs(coins, coinsSize, amount - coins[k]);
		if (subAns != -1) {
			tmp = MIN(tmp, subAns);
		}
	}
	if (tmp == INT_MAX) {
		return g_mem[amount] = -1;
	}
	return g_mem[amount] = tmp + 1;
}

int coinChange(int* coins, int coinsSize, int amount){
	int i, ans;
	
	g_mem = (int *)calloc(1, sizeof(int) * (amount + 1));
	for (i = 1; i <= amount; i++) {
		g_mem[i] = INT_MAX;
	}
	ans = Dfs(coins, coinsSize, amount);
	free(g_mem);
	return ans;
}

```
【自底向上 - 动态规划】
```
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
int coinChange(int* coins, int coinsSize, int amount){
	int *dp = (int *)calloc(1, sizeof(int) * (amount + 1));
	int i, j, tmp, ans;

	for (i = 1; i <= amount; i++) {
		dp[i] = -1;
	}

	for (i = 1; i <= amount; i++) {
		tmp = INT_MAX;
		for (j = 0; j < coinsSize; j++) {
			if (i < coins[j]) {
				continue;
			}
			if (dp[i - coins[j]] < 0) {
				continue;
			}
			tmp = MIN(tmp, dp[i - coins[j]]);
		}
		if (tmp != INT_MAX) {
			dp[i] = tmp + 1;
		}
	}
	ans = dp[amount];
	free(dp);
	return ans;
}
```
