```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        p2 = 0
        p1 = nums[0]
        for i in range(1, len(nums)):
            p2, p1 = p1, max(p1, p2+nums[i])        
        return p1
```
