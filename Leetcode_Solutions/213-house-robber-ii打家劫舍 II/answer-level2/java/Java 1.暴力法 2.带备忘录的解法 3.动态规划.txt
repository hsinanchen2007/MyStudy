相比于第一题，此题目将首位也作为相邻，假设总共有N个房子，思路是：
1.分两次求解，首先是第一家到第N-1家，求得偷得最多的值，记Max01;
2.之后再次求得第2家到第N家可以偷的最大值，记为Max02；
3.最后比较Max01与Max02，将最大的那个值返回。

最终结果： 暴力解法与带备忘录的求解超时，不明白为啥带备忘录的求解会超时，可能是使用了两个备忘录的缘故吧。
动态规划最终通过
```
    // 暴力解法
	public int rob(int[] nums) {
		if(nums.length == 0)
            return 0;
        if(nums.length == 1)
            return nums[0];
        if(nums.length == 2)
            return Math.max(nums[0], nums[1]);
		int start1 = 1;
		int start2 = 2;
		int end1 = nums.length - 1;
		int end2 = nums.length;
		int m1 = help(nums, start1, end1);
		int m2 = help(nums, start2, end2);
		int m = Math.max(m1, m2);
		return m;
	}

	public int help(int[] nums, int start, int end) {
		if (start == 1) {
			if (end == 1)
				return nums[0];
			if (end == 2)
				return Math.max(nums[0], nums[1]);
		}
		if (start == 2) {
			if (end == 2)
				return nums[1];
			if (end == 3)
				return Math.max(nums[1], nums[2]);
		}
		int m = Math.max(help(nums, start, end - 2) + nums[end - 1],
				help(nums, start, end - 1));
		return m;
	}
```

```	
	// 带备忘录
	public int rob(int[] nums) {
		if(nums.length == 0)
            return 0;
        if(nums.length == 1)
            return nums[0];
        if(nums.length == 2)
            return Math.max(nums[0], nums[1]);
		int[] memo1 = new int[nums.length + 1];
		int[] memo2 = new int[nums.length + 1];
		int start1 = 1;
		int start2 = 2;
		int end1 = nums.length - 1;
		int end2 = nums.length;
		int m1 = help(nums, start1, end1, memo1);
		int m2 = help(nums, start2, end2, memo2);
		int m = Math.max(m1, m2);
		return m;
	}

	public int help(int[] nums, int start, int end, int[] memo) {
		if (start == 1) {
			if (end == 1)
				return nums[0];
			if (end == 2)
				return Math.max(nums[0], nums[1]);
		}
		if (start == 2) {
			if (end == 2)
				return nums[1];
			if (end == 3)
				return Math.max(nums[1], nums[2]);
		}
		if(memo[end] != 0)
			return memo[end];
		memo[end] = Math.max(help(nums, start, end - 2, memo) + nums[end - 1],
				help(nums, start, end - 1, memo));
		return memo[end];
	}
```

```
	// 动态规划
	public int rob2(int[] nums) {
		int[] dp1 = new int[nums.length + 1];
		int[] dp2 = new int[nums.length + 1];
		dp1[1] = nums[0];
		dp1[2] = Math.max(nums[1], nums[0]);
		for (int i = 3; i < nums.length; i++) {
			dp1[i] = Math.max(nums[i - 1] + dp1[i - 2], dp1[i - 1]);
		}
		dp2[2] = nums[1];
		dp2[3] = Math.max(nums[1], nums[2]);
		for (int i = 4; i <= nums.length; i++) {
			dp2[i] = Math.max(nums[i - 1] + dp2[i - 2], dp2[i - 1]);
		}
		return Math.max(dp1[nums.length - 1], dp2[nums.length]);
	}
```
