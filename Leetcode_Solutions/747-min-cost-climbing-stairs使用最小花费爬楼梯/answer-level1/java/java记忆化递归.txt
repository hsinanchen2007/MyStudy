class Solution {
    public int minCostClimbingStairs(int[] cost) {
            int[] dp = new int[cost.length + 1];
            int n = cost.length;
            for (int i = 2; i <= n; i++){
                dp[i] = Math.min((dp[i-1] + cost[i-1]),(dp[i-2] + cost[i-2]));
            }
            return dp[n];
    }
}