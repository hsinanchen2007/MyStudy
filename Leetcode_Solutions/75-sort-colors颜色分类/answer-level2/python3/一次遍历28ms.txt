```Python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left = -1 if nums[0] else 0
        right = len(nums) if nums[-1] != 2 else len(nums) - 1
        i = left + 1
        while i < right:
            if nums[i] == 0:
                if i == left+1:
                    left += 1
                    i += 1
                else:
                    left += 1
                    nums[i], nums[left], i = nums[left], nums[i], left + 1
            elif nums[i] == 2:
                if i == right - 1:
                    break
                else:
                    right -= 1
                    nums[i], nums[right] = nums[right], nums[i]
            elif nums[i] == 1:
                i += 1
```