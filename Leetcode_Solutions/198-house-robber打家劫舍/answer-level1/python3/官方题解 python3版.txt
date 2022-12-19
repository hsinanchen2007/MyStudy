```
class Solution:
    def rob(self, nums: List[int]) -> int:
        preMax = 0
        curMax = 0
        for i in nums:
            preMax , curMax = curMax , max(preMax+i, curMax)
        return curMax
```
