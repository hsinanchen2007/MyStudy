假设F(N)为到数组下表N时的解，则
N = 0时 F(0) = nums[0]
N = 1时 F(1) = Max(nums[0],nums[1])
N >= 2时 F(N) = Max(F(N-1),F(N-2) + nums[N])
```
class Solution {
    public int massage(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }else{
            int [] dp = new int[nums.length];
        
            dp[0] = nums[0];
            int res = dp[0];
            for(int i = 1; i < nums.length; i++){
                if(i > 1){
                    dp[i] = Math.max(dp[i-1],dp[i-2] + nums[i]);
                    
                }else{
                    dp[i] = Math.max(nums[i],dp[i-1]);
                }
                res = Math.max(res,dp[i]);
            }
            return res;
        }
    }
}
```
