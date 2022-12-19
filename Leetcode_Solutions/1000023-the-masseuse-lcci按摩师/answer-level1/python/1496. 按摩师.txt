### 解题思路
动态规划
状态转移方程：dp[i] = max(dp[i-2]+nums[i], dp[i-1])

### 代码

```python3
class Solution:
    # 递归方法超时
    # def dp(self, nums, res):
    #     if len(nums) == 1:
    #         return res + nums[0]
    #     elif len(nums) == 0:
    #         return res
    #     return max(self.dp(nums[2:], res+nums[0]), self.dp(nums[3:], res+nums[1]))
    # 
    # def massage(self, nums: List[int]) -> int:
    #     res = self.dp(nums, 0)
    #     return res

    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [0 for _ in range(len(nums))]
        for i in range(len(nums)):
            if i == 0:
                dp[i] = nums[i]
            elif i == 1:
                dp[i] = max(nums[0], nums[1])
            else:
                dp[i] = max(dp[i-2]+nums[i], dp[i-1])
        return dp[-1]
```