```
class Solution {
    public boolean canJump(int[] nums) {
        if(nums == null || nums.length == 0){
            return false;
        }
        if(nums.length == 1){
            return true;
        }

        int len = nums.length;
        boolean[] dp = new boolean[len];

        for (int i = len - 2; i >= 0; i--) {
            dp[i] = len - 1 - i <= nums[i];
            if(!dp[i]){
                for (int j = i + 1; j < len; j++) {
                    if(dp[j] && j - i <= nums[i]){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
}
```
