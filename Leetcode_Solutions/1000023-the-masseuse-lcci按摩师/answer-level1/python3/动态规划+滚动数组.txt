### 解题思路
状态转移方程：dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
使用滚动数组，空间优化后，状态转移方程：dp[i % 2] = max(dp[(i - 1) % 2], dp[(i - 2) % 2] + nums[i])

### 代码

```python
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        size = len(nums)
        if size <= 2:
            return max(nums)
        dp = [0] * 2
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, size):
            dp[i % 2] = max(dp[(i - 1) % 2], dp[(i - 2) % 2] + nums[i])
        return dp[(size - 1) % 2]
```