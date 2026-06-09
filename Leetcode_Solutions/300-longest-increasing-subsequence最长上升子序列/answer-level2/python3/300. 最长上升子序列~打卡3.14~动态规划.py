### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if nums == []:
           return 0
        dp= [1] * len(nums)
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[j] + 1, dp[i])
        return max(dp)
```