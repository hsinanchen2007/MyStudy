class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        int[] dp = new int[n];
        for (int i = 0; i < n; i++){
            dp[i] = Math.max(((i > 1 ? dp[i-2] : 0) + nums[i]),(i > 0 ? dp[i-1] : 0));
        }
        return dp[n - 1];
    }
}