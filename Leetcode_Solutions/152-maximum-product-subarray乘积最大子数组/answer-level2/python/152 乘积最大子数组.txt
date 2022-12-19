### 解题思路
动态规划：
    cur_max = max(pre_max * num, pre_min * num, num)
    cur_min = min(pre_max * num, pre_min * num, num)

### 代码

```python
class Solution:
    def maxProduct(self, nums):

        n = len(nums)
        min_dp = [1] * (n+1)
        max_dp = [1] * (n+1)
        ans = float('-inf')

        for i in range(1, n+1):
            max_dp[i] = max(max_dp[i-1]*nums[i-1], min_dp[i-1]*nums[i-1], nums[i-1])
            min_dp[i] = min(max_dp[i-1]*nums[i-1], min_dp[i-1]*nums[i-1], nums[i-1])
            ans = max(ans, max_dp[i])

        return ans
        
```