class Solution {
    /*
    dp[i][0]=max(dp[i-1][0],dp[i-1][1]) //表示第i个人不接，最优解
    dp[i][1]=dp[i-1][0]+nums[i]  //表示第i个人接，最优解
    */
    public int massage(int[] nums) {
        int[][] dp = new int[nums.length][2];
        int len = nums.length;
        if(len<=0) return 0;
        dp[0][0]=0;
        dp[0][1]=nums[0];
        for(int i=1;i<len;i++){
            dp[i][0]=Math.max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+nums[i];
        }
        return dp[len-1][0]>dp[len-1][1]?dp[len-1][0]:dp[len-1][1];
    }
}