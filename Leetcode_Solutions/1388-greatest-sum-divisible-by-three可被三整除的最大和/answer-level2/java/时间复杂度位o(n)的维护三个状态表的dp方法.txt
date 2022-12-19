维护三个dp数组，分别存放nums数组索引0到i这个范围内可以整除3的最大值，除以3余1的最大值以及除以3余2的最大值，代码写得有点繁琐，繁琐的原因在于初始化的时候三个数组都为0，有大神知道如何更简答的实现，敬请赐教。
```
class Solution {
    public int maxSumDivThree(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n+1];
        int[] dp1 = new int[n+1];
        int[] dp2 = new int[n+1];
        for(int i = 1;i <= n;i++)
        {
            if(nums[i-1]%3==0)
            {
                dp[i]=nums[i-1]+dp[i-1];
                if(dp1[i-1]!=0)
                {
                    dp1[i]=dp1[i-1]+nums[i-1];
                }
                if(dp2[i-1]!=0)
                {
                    dp2[i]=dp2[i-1]+nums[i-1];
                }
            }else if(nums[i-1]%3 == 1)
            {
                if(dp2[i-1]!=0)
                {
                    dp[i] = Math.max(dp[i-1],nums[i-1]+dp2[i-1]);
                }
                else
                {
                    dp[i] = dp[i-1];
                }
                dp1[i] = Math.max(dp1[i-1],nums[i-1]+dp[i-1]);
                if(dp1[i-1]!=0)
                {
                    dp2[i] = Math.max(dp2[i-1],nums[i-1]+dp1[i-1]);
                }
                else
                {
                    dp2[i] = dp2[i-1];
                }
            }else
            {
                if(dp1[i-1]!=0)
                {
                    dp[i] = Math.max(dp[i-1],nums[i-1]+dp1[i-1]);
                }
                else
                {
                    dp[i] = dp[i-1];
                }
                if(dp2[i-1]!=0)
                {
                    dp1[i] = Math.max(dp1[i-1],nums[i-1]+dp2[i-1]);
                }
                else
                {
                    dp1[i] = dp1[i-1];
                }
                dp2[i] = Math.max(dp2[i-1],nums[i-1]+dp[i-1]);
                
            }
        }
        return dp[n];
        
    }
}
```
