```
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        nums.sort()
        dp = []
        for i in range(target+1):
            if i in nums:
                dp.append(1)
            else:
                dp.append(0)
        for i, v in enumerate(dp):
            for j in nums:
                if i < j:
                    break
                dp[i] += dp[i-j]
        return dp[-1]
```
