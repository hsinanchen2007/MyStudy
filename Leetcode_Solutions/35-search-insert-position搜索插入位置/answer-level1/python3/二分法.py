```      
class Solution:
    def searchInsert(self, nums, target) -> int:
        if not nums:
            return 0
        if nums[0] > target:
            return 0
        if nums[-1] < target:
            return len(nums)
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] > target:
                right = mid - 1
            if nums[mid] < target:
                left = mid + 1
        if left == mid:
            return mid
        if right == mid:
           return left
```
**菜鸟第一次发，嘿嘿**
