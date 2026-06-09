### 解题思路
动态规划，这类还是很简单的，有点类似于0-1背包问题。
dp[i]代表长度为i的数组，当前最长时间。
dp[i] = dp[i-1],第i个时间不要。
dp[i] = dp[i-2] + nums[i]，第i个时间要。
dp[i] = max(dp[i-1],dp[i-2] + nums[i]),从要和不要中选取最大值。

初始化：
dp[0] = nums[0]
dp[1] = max(nums[0],nums[1])
搞定。
### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        arr_size = len(nums)
        if arr_size < 2:
            return nums[0]
        dp = [0] * arr_size
        dp[0] = nums[0]
        dp[1] = max(nums[0],nums[1])
        for i in range(2, arr_size):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        return dp[-1]
```