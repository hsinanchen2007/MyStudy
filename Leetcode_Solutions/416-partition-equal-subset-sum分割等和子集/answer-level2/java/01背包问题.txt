执行用时 :7 ms, 在所有 java 提交中击败了95.20% 的用户
内存消耗 :36.5 MB, 在所有 java 提交中击败了89.27%的用户
```
class Solution {
    public boolean canPartition(int[] nums) {
        if(nums == null || nums.length < 2)
            return false;
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        if((sum&1) != 0)
            return false;
        sum = (sum>>1) ;
        int[] dp = new int[sum+1];
        dp[0] = 1;
        for(int num : nums){
            for(int i = sum; i >= num; i--){
                dp[i] += dp[i-num];
            }
        }
        return dp[sum] == 0 ? false : true;
    }
}
```
