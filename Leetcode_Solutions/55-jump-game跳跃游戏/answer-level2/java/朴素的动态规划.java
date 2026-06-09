把问题当成怎么跳最远（最远的index，可能大于数组长度）来做，i处能到达的最远位置是max(从i处之前跳能到达的最远位置，从i处跳能到达的最远位置)，前提是i-1处能到达i处。
```
class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length < 2) {
            return true;
        }
        int[] dp = new int[nums.length]; // dp[i] = max(dp[i-1], nums[i] + i)
        dp[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            dp[i] = Math.max(dp[i - 1], nums[i] + i);
            if (dp[i - 1] < i) {
                return false;
            }
            if (dp[i] >= nums.length - 1) {
                return true;
            }
        }
        return false;
    }
}
```
