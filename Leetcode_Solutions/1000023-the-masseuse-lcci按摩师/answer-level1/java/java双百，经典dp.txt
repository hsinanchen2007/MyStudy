```
class Solution {
    public int massage(int[] nums) {
        int len=nums.length;
        int[] dp=new int[len];
        int ans=0;
        
        for(int i=0;i<nums.length;i++)
        {   dp[i]=nums[i];
            for(int j=i-2;j>=0;j--)
            {
                dp[i]=Math.max(dp[j]+nums[i],dp[i]);
                
            }
         ans=Math.max(dp[i],ans);
        }
        return ans;
    }
}
```
