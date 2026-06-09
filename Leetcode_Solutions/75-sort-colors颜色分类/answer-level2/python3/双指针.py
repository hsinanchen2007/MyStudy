```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        if size == 0:
            return []
        
        if size == 1:
            return nums
        
        i, j = 0, size-1
        k = 0

        while k <= j:
            if nums[k] == 0:
                nums[i], nums[k] = nums[k], nums[i]
                i += 1
                k += 1
            elif nums[k] == 2:
                # 这里k不会往前走
                nums[k], nums[j] = nums[j], nums[k]
                j -= 1
            else:
                k += 1
        
        return nums
```
