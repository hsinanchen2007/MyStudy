动态规划问题，定义一个与输入数组等长的dp数组，dp[i] 代表小偷从第1号到第i+1号屋子偷钱的最大收益。  
可简单推理出，如果偷了第i+1号屋子，收益为nums[i] + dp[i-2] (因为相邻不可偷)。如果不偷，收益为dp[i-1].
逐步求最大值即可。
 
```java []
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        int dp[] = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0],nums[1]);
        for(int i= 2;i<n;i++){
            dp[i] = Math.max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
}
```
