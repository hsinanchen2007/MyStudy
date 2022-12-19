```
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            if nums[i]<nums[i-1]:
                return i-1
        return len(nums)-1
```
