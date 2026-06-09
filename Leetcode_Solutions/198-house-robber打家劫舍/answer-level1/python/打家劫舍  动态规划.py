### 解题思路
dp[i] = max(dp[i-2] + nums[i],dp[i-1] - nums[i-1] + nums[i])

### 代码

```python
class Solution(object):
    def rob(self, nums):
        if not nums:
            return 0
        dp = [0]*len(nums)
        if len(nums) <= 2:
            return max(nums)
        if len(nums) > 2:
            dp[0] = nums[0]
            dp[1] = nums[1] 
            for i in range(2,len(nums)):
                dp[i] = max(dp[i-2] + nums[i],dp[i-1] - nums[i-1] + nums[i])
            return max(dp)
```