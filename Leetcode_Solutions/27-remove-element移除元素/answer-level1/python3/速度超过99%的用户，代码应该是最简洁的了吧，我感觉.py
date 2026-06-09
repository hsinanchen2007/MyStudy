```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        for i,c in enumerate(nums):
            while nums[i:] and nums[i] == val:
                del nums[i]
        return len(nums)
```
