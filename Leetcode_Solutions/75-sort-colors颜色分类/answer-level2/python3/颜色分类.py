计数排序：
```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        x, y, z = 0, 0, 0
        for i in nums:
            if i == 0:
                x += 1
            elif i == 1:
                y += 1
            else:
                z += 1
        nums[:x], nums[x:x+y], nums[x+y:] = [0]*x, [1]*y, [2]*z
        return nums
```

三路排序：
```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        lt, i, gt = -1, 0, len(nums)
        while i < gt:
            if nums[i] == 0:
                lt += 1
                nums[lt], nums[i] = nums[i], nums[lt]
                i += 1
            elif nums[i] == 1:
                i += 1
            else:
                gt -= 1
                nums[i], nums[gt] = nums[gt], nums[i]
        return nums
```
