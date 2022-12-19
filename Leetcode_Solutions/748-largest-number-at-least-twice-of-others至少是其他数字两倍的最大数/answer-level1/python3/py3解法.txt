```
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        r = max(nums)
        index=0
        for i in range(len(nums)):
            if r!=nums[i] and r<2*nums[i]:
                return -1
            if r==nums[i]:
                index=i
        return index
```
