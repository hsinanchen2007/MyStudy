```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        # dp = min(dp[i], 左边可到达该位置的dp+ 1
        # 使用倒序遍历进行剪枝
        # Time complexity: O(n**2)
        # Space complexity: O(n)
        if nums == []: return 0
        dp = [float('inf')] * len(nums)
        dp[0] = 0
        for i in range(len(nums)):
            for j in reversed(range(1, nums[i] + 1)): # 倒序遍历用于剪枝
                if i + j < len(nums):
                    if dp[i] + 1 <= dp[i + j]: dp[i + j] = dp[i] + 1
                    else: break
        return dp[-1]
```