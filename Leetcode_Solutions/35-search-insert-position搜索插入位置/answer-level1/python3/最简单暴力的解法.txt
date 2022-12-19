```
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for i,e in enumerate(nums):
            if e>=target:
                return i
            else:
                pass
        return len(nums)
```