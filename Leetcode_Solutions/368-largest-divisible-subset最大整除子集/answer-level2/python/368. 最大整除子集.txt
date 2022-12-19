### 代码

```python
class Solution:
    def largestDivisibleSubset(self, nums):
        nums = sorted(nums)
        dp = [[x] for x in nums]
        ans = []
        for i in range(len(nums)):
            for j in range(i):
                if nums[i]%nums[j] == 0 and len(dp[j])+1>len(dp[i]):
                    dp[i]  = dp[j] + [nums[i]]
            if len(dp[i])>len(ans):
                ans = dp[i]
        return ans
```