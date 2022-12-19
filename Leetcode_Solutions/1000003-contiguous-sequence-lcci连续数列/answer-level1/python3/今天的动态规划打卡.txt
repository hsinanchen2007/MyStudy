### 解题思路
状态:dp[i]表示到nums[i]为止的连续数列最大和
初态:dp[0] = nums[0]
状态转移方程:dp[i] = max(nums[i],dp[i-1]+nums[i])考虑到前面的和可能有负数

容易踩坑的点：return max(dp)而不是return dp[-1]。leetcode有一道类似的，第一次做的时候踩雷了。

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [0] * len(nums)
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        else:
            dp[0] = nums[0]
            for i in range(1,len(nums)):
                dp[i] = max(nums[i],dp[i-1]+nums[i])
        return max(dp)
        
```