### 解题思路
dp[i]表示以i结尾的子序列的长度。每个nums[i]都是一个元素，因此初态dp[i]全部为1。状态转移方程是这样考虑的：如果nums[i]之前存在比它小的nums[j]，那么dp[i]就等于dp[j]+1，需要注意的是nums[i]之前比它小的元素可能不止一个，因此要找出最大的那一个。所以状态转移方程应该是dp[i] = max(dp[j]+1,dp[i])。
看了覃超老师的动态规划，对着他说的状态定义、初态、状态转移方程一点点写出答案，属实心满意足。不过执行用时和内存消耗都很大，还需要多学习！

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [1]*len(nums)
        res = 1
        for i in range(1,len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[j]+1 , dp[i])
                    res = max(res,dp[i])
        return res
```