### 解题思路
dp[i]表示**包含当前元素nums[i]**时的最大子序列长度，对于每一个dp[i]的nums[i]的值能否包含进前面i-1个中的某一个序列中，需要将其与前面元素进行比较

### 代码

```python
class Solution(object):
    def lengthOfLIS(self, nums):
        if not nums:return 0
        dp = [1] * len(nums)
        for i in range(1,len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i],dp[j] + 1) 
        return max(dp)
```