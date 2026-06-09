```
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums = sorted(nums)
        dp = [[x] for x in nums]
        maxseq = []
        for i in range(len(nums)):
            for j in range(i):
                if nums[i]%nums[j] == 0 and len(dp[j])+1>len(dp[i]):
                    dp[i]  = dp[j]+nums[i:i+1]
            if len(dp[i])>len(maxseq):
                maxseq = dp[i]
        return maxseq
```

```
