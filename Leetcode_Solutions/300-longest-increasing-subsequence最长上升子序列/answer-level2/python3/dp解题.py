解题思路：
dp(动态规划)：
dp[i] = max(dp[0],dp[1],dp[j]...dp[i-1]) + 1 ，0<=j<i但是有一个前提条件是：num[j]<nums[i]
看代码：
```
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        res = [0] * n
        for i in range(n):
            res[i] = max([res[j] for j in range(i) if nums[i]>nums[j]]) + 1 if [res[j] for j in range(i) if nums[i]>nums[j]] else 1
        return max(res) if res else 0
```
