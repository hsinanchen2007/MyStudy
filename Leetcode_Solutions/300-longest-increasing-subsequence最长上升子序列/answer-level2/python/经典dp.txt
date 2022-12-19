### 解题思路
经典dp。 dp表示以i结尾的最长子序列大小，状态转移方程为dp[i] = max(dp[i], dp[j] + 1), if nums[i-1] > nums[j-1]:

### 代码

```python
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        if not nums: return res
        n = len(nums)
        dp = [1]*(n+1) # dp表示以i结尾的最长子序列大小
        dp[0] = 0
        for i in range(1, n+1):
            for j in range(i):
                if nums[i-1] > nums[j-1]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)

```