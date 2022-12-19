### 解题思路
	入门DP，注意递归会超时

### 代码

```c
#include <stdlib.h>
#define MAX(a,b) (a>b?a:b)

int massage(int* nums, int numsSize) {
	if (nums == NULL || numsSize == 0) {
		return 0;
	}

	int *dp = (int*)malloc(sizeof(int) * numsSize);
	if (numsSize == 1) return nums[0];
	if (numsSize == 2) return MAX(nums[0], nums[1]);
	dp[0] = nums[0];
	dp[1] = MAX(nums[0], nums[1]);
	int ans = 0;
	
	for (int i = 2; i < numsSize; ++i) {
		dp[i] = MAX(dp[i - 1], dp[i - 2] + nums[i]);
		ans = ans > dp[i] ? ans : dp[i];
	}
	return ans;
}
```