nums数组：10      9       2       5       3       7       101     18
从后往前数递增的个数
dp数组：      2         2       4       3       3       2       1           1

```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1 for i  in range(len(nums))]
        for i in reversed(range(len(nums))):
            if i == len(nums)-1:
                dp[i] = 1
                continue
            for j in range(i, len(nums)):
                if nums[i]<nums[j] and dp[i]<dp[j]+1:
                    dp[i] = dp[j] + 1
        temp = 0
        for i in range(len(nums)):
            if dp[i] > temp:
                temp = dp[i]
        return temp
```
