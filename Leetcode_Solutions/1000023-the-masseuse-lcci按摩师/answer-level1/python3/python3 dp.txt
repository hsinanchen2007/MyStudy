```
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0

        dp = [0 for _ in range(len(nums))]
        dp[0] = nums[0]

        for i in range(1, len(dp)):
            for j in range(i):
                if i - j > 1:
                    dp[i] = max(dp[i], dp[j] + nums[i])
                else:
                    dp[i] = max(dp[i], dp[j - 1] + nums[i], dp[j])
        return dp[-1]
```
