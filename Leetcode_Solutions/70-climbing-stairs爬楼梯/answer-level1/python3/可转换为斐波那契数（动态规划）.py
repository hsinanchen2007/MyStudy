```
class Solution:
    def climbStairs(self, n: int) -> int:
        nums = [None]*(n+1)
        nums[0] = 1
        nums[1] = 1
        i = 2
        while i <= n:
            nums[i] = nums[i-1] + nums[i-2]
            i += 1
        return nums[n]
```
