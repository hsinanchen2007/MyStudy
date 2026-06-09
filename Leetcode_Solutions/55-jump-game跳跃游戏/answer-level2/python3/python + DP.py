```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # method : DP
        dp = [-1] * len(nums)
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            dp[i] = max(dp[i], dp[i - 1] - 1)
            if dp[i] >= 0: dp[i] = max(dp[i], nums[i])
            else: break
        return True if dp[-1] != -1 else False
```