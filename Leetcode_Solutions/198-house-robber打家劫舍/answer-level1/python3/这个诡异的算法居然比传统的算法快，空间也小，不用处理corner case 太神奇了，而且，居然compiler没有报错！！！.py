### 解题思路

请问这个奇葩方法为什么不报错！！！！
特别是在for里面，dp[i-2]但我的i是从0开始的！！！！
大家可以那这个代码跑一下，下面那一个
```

N = len(nums)
dp = [0] * (N+1)
for i in range(0, N):
    dp[i] = max(dp[i-2]+nums[i], dp[i-1])
return max(dp)
```

### 代码

```python3
# class Solution:
#     def rob(self, nums: List[int]) -> int:
#         if not nums:
#             return 0

#         N = len(nums)

#         dp = [0] * (N+1)
#         dp[1] = nums[0]

#         for i in range(2, N+1):
#             dp[i] = max(dp[i-2]+nums[i-1], dp[i-1])

#         return dp[-1]

class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0

        N = len(nums)

        dp = [0] * (N+1)

        for i in range(0, N):
            dp[i] = max(dp[i-2]+nums[i], dp[i-1])

        return max(dp)
```