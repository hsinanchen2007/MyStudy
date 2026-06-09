```
class Solution:
    def massage(self, nums: List[int]) -> int:
        n = len(nums)
        if not nums:
            return 0
        if n ==1:
            return nums[0]

        #O(N）空间复杂度
        # dp = [0 for i in range(n)]                    
        # dp[0] = nums[0]
        # dp[1] = max(nums[1],dp[0])
        # for i in range(2,n):
        #     dp[i] = max(dp[i-2]+nums[i],dp[i-1])
        # return dp[-1]


        #O（1）空间复杂度
        dp0 = nums[0]
        dp1 = max(nums[1],dp0)
        for i in range(2,n):
            dp0 = max(dp0+nums[i],dp1)
            dp1,dp0 = dp0,dp1
        return dp1
```
