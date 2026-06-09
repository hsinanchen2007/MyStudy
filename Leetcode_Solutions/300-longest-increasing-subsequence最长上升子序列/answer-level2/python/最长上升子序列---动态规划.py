# ### 解题思路
# 我还是太菜了😂，想到了动态规划，也列出来dp[i]的意思，就是没有想出来dp[i]的关系式，一直想着dp[i-1],dp[i-2],dp[i]的关系。
# 如官方给的思路一样。
# dp[i]代表长度为i的数组的最长升序子序列。
# 那么
# dp[i]初始化为1，代表自身长度。
# 如果nums[i] > nums[j]，说明dp[i] = max(dp[j] + 1)
# 如果nums[i] < nums[j],说明dp[i] = max(dp[j])
# 这里的j范围为：0...i-1，小于i的数组长度。
# 总结推到公式如下：
# dp[i] = max(dp[i],dp[j]), 0<=j<i且nums[i] > nums[j]

# ### 代码

# ```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums: return 0
        dp = []
        for i in range(len(nums)):
            dp.append(1)  #元素自身长度
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[j]+1, dp[i])
        return max(dp)
# ```