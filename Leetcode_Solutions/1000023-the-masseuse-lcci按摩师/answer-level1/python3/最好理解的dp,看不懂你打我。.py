### 解题思路
本题的动态规划思想是:dp[i]表示的截止到i个人最大的答案(包括第i个人)。既然选择了
当前的nums[i],那么之前的时间和应该是从dp[:i-1]里面选一个最大的加上自身。
那么dp方程就是dp[i]=nums[i]+max(dp[:i-1]),注意最后返回的是dp中最大的一个即可。

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        elif len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums)
        else:
            dp = [0]*len(nums)
            dp[0] = nums[0]
            dp[1] = nums[1]
            res = nums[0]
            for i in range(2,len(nums)):
                res = max(res,dp[i-2])
                dp[i] = res+nums[i]
            return max(dp)

```