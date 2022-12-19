### 解题思路
一不小心还是掉到了陷阱里，
最开始用得错误的方程
dp[n] = max(dp[n-1], nums[n] + dp[n-2]))
但其实状态转换方程应该是
dp[n] = max(dp[n-1], nums[n] + max(dp[0]...dp[n-2]))
![image.png](https://pic.leetcode-cn.com/924f2d9451f803d6f8b53badf06dd03faadbeb764ea6e6b1e2265d298a55437c-image.png)

### 代码

```c
#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))
int proc(int *nums, int numsSize)
{
	int i;
	int max;
	int dp0, dp1, dp2;
	dp0 = nums[0];
	dp1 = nums[1];
	max = dp0;
	for (i = 2; i < numsSize; i++) {
		dp2 = MY_MAX(dp1, max + nums[i]);
		max = MY_MAX(max, dp1);
		dp0 = dp1;
		dp1 = dp2;
	}
	return dp2;
}
int massage(int* nums, int numsSize){
    if (numsSize <= 0 || nums == NULL) {
		return 0;
	}
	if (numsSize == 1) {
		return nums[0];
	}
	if (numsSize == 2) {
		return MY_MAX(nums[0], nums[1]);
	}
	return proc(nums, numsSize);
}
```