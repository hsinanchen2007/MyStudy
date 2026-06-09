```
class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int n:nums) sum+=n;
        if(sum%2!=0) return false;
        int target = sum/2;
        boolean[] dp = new boolean[target+1];
        for(int i=0;i<nums.length;i++){
            for(int j=target;j>=nums[i];j--){
                if(nums[i]==j){
                    dp[j]=true;
                    continue;
                }
                if(nums[i]<j){
                    dp[j] = dp[j] || dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
}
```
背包问题优化，从后到前遍历只用一维数组即可。
