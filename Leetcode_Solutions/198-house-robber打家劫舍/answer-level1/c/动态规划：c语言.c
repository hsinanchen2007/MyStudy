### 解题思路
此处撰写解题思路
使用动态规划来解决，递推公式为：dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])。关键是dp[0]和dp[1]的初始化，dp[0]=nums[0], dp[1]要初始化成nums[0]和nums[1]中较大的那个，因为dp[i]的意义为打劫前i个所获取的最大值。
### 代码

```c
int max(int a, int b) {
	 return a>b ? a : b;
}

//动态规划解决
int rob(int* nums, int numsSize){
	int *dp = (int *)malloc((numsSize)*sizeof(int));
	int i;
	if (numsSize > 0){
		dp[0] = nums[0];
	}
	else{
		return 0;
	}

	if (numsSize > 1){
		dp[1] = max(nums[0], nums[1]);
	}

	for (i = 2; i < numsSize; i++){
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}
	return dp[numsSize - 1];
}
```