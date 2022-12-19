动态规划
```Java []
class Solution {
    public int massage(int[] nums) {
        int length = nums.length;
        if(length==0) return 0;
        if(length==1) return nums[0];
        if(length==2) return Math.max(nums[0], nums[1]);

        int[] dp = new int[length+1];
        dp[2] = Math.max(nums[0], nums[1]);
        dp[1] = nums[0];
        dp[0] = 0;

        for(int i=3;i<=length;i++) {
            dp[i] = Math.max(dp[i], dp[i-2]+nums[i-1]);
            dp[i] = Math.max(dp[i], dp[i-1]);
        }
        return dp[length];
    }
}
```
