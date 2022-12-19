### 解题思路
1、动态规划，本质就是对于每个数有“选”、“不选”两种可能
2、能用动态规划的，一般都可以用记忆化递归

虽然两者时间复杂度一样，但是还是动态规划快，因为递归得不停的出入栈

### 代码
【记忆化递归】
```c
#include <stdio.h>
#define MAX_N 256

static char g_mem[MAX_N][10001];

static bool Dfs(int *nums, int len, int step, int tar)
{
	bool ret1, ret2;
	if (tar == 0) {
		return true;
	}
	if (step >= len) {
		return false;
	}

	if (tar < 0) {
		return false;
	}

	if (g_mem[step][tar] != -1) {
		return g_mem[step][tar];
	}

	ret1 = Dfs(nums, len, step + 1, tar);
	ret2 = Dfs(nums, len, step + 1, tar - nums[step]);
	return g_mem[step][tar] = ret1 || ret2;
}

bool canPartition(int* nums, int numsSize)
{
	int sum = 0;
	int i, j;
	int tar;

	memset(g_mem, -1, sizeof(g_mem));
	for (i = 0; i< numsSize; i++) {
		sum += nums[i];
	}

	if (sum % 2 == 1) {
		return false;
	}
	tar = sum / 2;
	return Dfs(nums, numsSize, 0, tar);	
}

```

【动态规划】
```
#include <stdio.h>
#define MAX_N 256

bool canPartition(int* nums, int numsSize)
{
	int sum = 0;
	int i, j;
	int tar;
	bool dp[MAX_N][10001] = { 0 };

	for (i = 0; i< numsSize; i++) {
		sum += nums[i];
	}

	if (sum % 2 == 1) {
		return false;
	}
	tar = sum / 2;

	for (j = 0; j <= tar; j++) {
		if (nums[0] == j) {
			dp[0][j] = true;
		}
	}

	for (i = 1; i < numsSize; i++) {
		for (j = 0; j <= tar; j++) {
			if (j < nums[i]) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
			}
		}
	}

	return dp[numsSize - 1][tar];
}

```
