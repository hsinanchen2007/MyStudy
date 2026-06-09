```
class Solution:
    def searchInsert(self, nums, target):
        left_pointer = 0
        right_pointer = len(nums) - 1
        if nums[right_pointer] < target:
            return right_pointer + 1
        if nums[left_pointer] > target:
            return left_pointer
        if nums[right_pointer] == target:
            return right_pointer
        if nums[left_pointer] == target:
            return left_pointer
        while left_pointer < right_pointer - 1:
            mid = (left_pointer + right_pointer) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] > target:
                right_pointer = mid
            if nums[mid] < target:
                left_pointer = mid
        return left_pointer + 1
```
