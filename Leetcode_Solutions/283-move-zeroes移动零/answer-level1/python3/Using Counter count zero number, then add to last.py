```
class Solution:
 def moveZeroes(self, nums: List[int]) -> None[]():
        """
        Do not return anything, modify nums in-place instead.
        """
        from collections import Counter
        nums_c = Counter(nums)
        n = nums_c[0]
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] == 0:
                nums.pop(i)
        nums += n*[0]
        return nums
```
