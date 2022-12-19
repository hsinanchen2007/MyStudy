### 解题思路
看代码注释即可

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if len(nums) <= 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        dp = [0] * len(nums) # 从0到i的最优解
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1]) 
        for i in range(2, len(nums)):
            # 每次可以选择加上自己，使用前一个数据
            # 或者不考虑自己，直接使用上一个数据
            dp[i] = max(dp[i-1], nums[i] + dp[i-2])
        return dp[-1]
```