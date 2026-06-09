### 解题思路
先看300题, dp[i]定义为以i结尾的字符最长上升子序列长度
此时再定义count[i], 代表通往i的最长上升子序列个数

### 代码

```python3
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        l = len(nums)
        dp = [1]*l
        count = [1]*l
        for i in range(l):
            for j in range(i):
                if nums[i]>nums[j]:
                    if dp[j]+1>dp[i]:# 代表第一次遇到最长子序列
                        dp[i] = max(dp[j]+1, dp[i])
                        count[i] = count[j]
                    elif dp[j]+1==dp[i]: # 代表之前已经遇到过最长子序列
                        count[i] += count[j]
        res, tmp = 0, max(dp)
        for i in range(l):
            if dp[i]==tmp: res+=count[i]
        return res
```