### 解题思路
1、可以这样思考：dp方程中的值的含义是：取或者不取当前房子取得的最大的价值。
  - 如果**取**:那么此时就是nums[i]+nums[i-2]的值要>nums[i-1]
  - 如果**不取**：那么就是此时就是取得nums[i-1]的值
  - 所以dp[i]中存的永远都是取或者不取nums[i]时的最大价值数

### 代码

```

class Solution:
    def rob(self, nums: List[int]) -> int:
        ##动态规划法来解决
        ##  nums = [2,1,1,3]
        ##  dp = [2,2,3,5]
        dp = nums
        lens = len(nums)
        if lens==0:
            return 0
        if lens==1:
            return nums[0]
        if lens==2:
            return max(nums[0],nums[1])
        dp[0] = nums[0]
        dp[1] = max(nums[0],nums[1]) 
        for i in range(2,lens):
            dp[i] = max(dp[i-2]+nums[i],dp[i-1])

        return max(dp)

```