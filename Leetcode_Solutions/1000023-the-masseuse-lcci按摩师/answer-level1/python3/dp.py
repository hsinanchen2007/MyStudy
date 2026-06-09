### 解题思路
dp，注意边界处理就好了。

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [0]*len(nums)
        # dp [0] = nums[0]
        for i, num in enumerate(nums):
            if i < 2:
                dp[i] = max(num, dp[i-1])
                continue
            dp[i] = max(dp[i-2] + num, dp[i-1])
        return dp[len(nums)-1]
```