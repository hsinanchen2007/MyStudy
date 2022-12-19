### 解题思路
按照官方思路动态规划写的

### 代码

```c
int maxSubArray(int* nums, int numsSize) {
	if (numsSize == 1)
		return nums[0];
	int dp = nums[0], max = nums[0];
	for (int i = 1; i < numsSize; ++i)
	{
		dp = nums[i] > nums[i] + dp ? nums[i] : nums[i] + dp;
		max = dp > max ? dp : max;
	}
	return max;
}
```