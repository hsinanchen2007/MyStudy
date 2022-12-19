```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        ct = len(nums)
        s = sum(nums)
        return (ct * (ct + 1)) // 2 - s
```
