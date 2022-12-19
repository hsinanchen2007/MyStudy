```java []
	public int maxSubArray(int[] nums) {
		int[] dp = new int[nums.length];
		int i = 0;
		dp[0] = nums[0];
		int max = dp[0];
		for (i = 1; i < nums.length; i++) {
                        //dp方程
			dp[i] = dp[i-1] + nums[i] < nums[i] ? nums[i] : dp[i-1] + nums[i];
                        //用max存储当时出现的最大值
			max = max > dp[i] ? max : dp[i];
		}
		return max;
	}
```
