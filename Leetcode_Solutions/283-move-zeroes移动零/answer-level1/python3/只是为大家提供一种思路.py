```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if 0 not in nums:return nums
        count = nums.count(0)
        while count > 0:
            count -= 1
            i = nums.index(0)
            nums.pop(i)
            nums.append(0)
```
