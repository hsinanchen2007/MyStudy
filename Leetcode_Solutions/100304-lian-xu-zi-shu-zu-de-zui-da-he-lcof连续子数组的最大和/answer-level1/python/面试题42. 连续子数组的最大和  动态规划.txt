### 解题思路
dp[i] = max(nums[i],nums[i] + dp[i-1])

### 代码

```python
class Solution(object):
    def maxSubArray(self, nums):
        dp = [0]*len(nums)
        dp[0] = nums[0]
        for i in range(1,len(nums)):
            dp[i] = max(nums[i],nums[i] + dp[i-1])
        return max(dp)
```