```
/**
     * 解法二：动态规划
     * 设计状态：dp[i]用来保存当前为止的最大子序和，即在下标[0,i]之间的最大子序和
     * 状态转移方程：dp[i] = Math.max(dp[i-1] + nums[i],nums[i]),即dp[i] = Math.max(当前位置的元素加上前面的最大子序和 || 当前位置的元素)
     */
    public int maxSubArrayDp(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        int max = nums[0];
        for(int i = 1;i < nums.length;i++){
            dp[i] = Math.max(nums[i] + dp[i-1],nums[i]);
            max = Math.max(max,dp[i]);
        }
        return max;
    }
```
