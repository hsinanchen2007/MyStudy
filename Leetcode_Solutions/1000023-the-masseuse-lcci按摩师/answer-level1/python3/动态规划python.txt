dp[i][0] 不服务第i位的累积时常，可以是服务过上一位也可以连续不服务。取时常大的。
dp[i][1] 服务第i位的累积时常，只能是没有服务过上一位。
```
class Solution:
    def massage(self, nums) -> int:
        if not nums:return 0
        n = len(nums)
        dp=[[0]*2 for _ in range(n)]
        dp[0][1] = nums[0]
        for i in range(1,n):
            dp[i][0]=max(dp[i-1][1],dp[i-1][0])
            dp[i][1]=dp[i-1][0]+nums[i]
        return max(dp[-1])
```
