```
class Solution:
    def massage(self, nums: List[int]) -> int:
        i = 0  # dp[n-2]
        j = 0  # dp[n-1]
        for n in nums:
            i = j if j>i+n else i+n 
            i, j = j, i 
        return j
```