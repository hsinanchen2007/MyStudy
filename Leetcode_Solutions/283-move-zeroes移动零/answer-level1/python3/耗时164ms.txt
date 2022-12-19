```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n2 = 0
        while 0 in nums:
            nums.remove(0)
            n2 += 1
        while n2 != 0:
            nums.append(0)
            n2 -= 1
```
