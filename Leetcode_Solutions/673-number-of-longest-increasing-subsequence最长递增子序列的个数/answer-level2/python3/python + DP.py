```python
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        # cnt of increasing sequence
        if nums == []: return 0
        dp = [1] * len(nums)
        cnt = [1] * len(nums)
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        cnt[i] = cnt[j]
                    elif dp[j] + 1 == dp[i]:
                        cnt[i] += cnt[j]
        max_cnt = max(dp)
        ans = 0
        for i, d in enumerate(dp):
            if d == max_cnt: ans += cnt[i]
        return ans
```