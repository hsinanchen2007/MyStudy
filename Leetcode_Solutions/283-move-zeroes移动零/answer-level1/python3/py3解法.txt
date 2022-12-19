```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        tag = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[tag],nums[i] = nums[i],nums[tag]
                tag += 1
```
