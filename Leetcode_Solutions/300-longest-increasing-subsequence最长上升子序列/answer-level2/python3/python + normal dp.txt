```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if nums == []: return 0
        dp = [1] * len(nums)
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[j] + 1, dp[i])
        return max(dp)
```