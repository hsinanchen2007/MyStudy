```
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return 0
        for i in range(len(nums)):
            if nums[i] == target:
                return i
            if len(nums) == 1:
                if nums[0] > target:
                    return 0
                elif nums[len(nums)-1] < target:
                    return len(nums)
            elif nums[0] > target:
                    return 0
            elif nums[i] < target and target < nums[i+1]:
                return i+1
            elif nums[len(nums)-1] < target:
                return len(nums)
```
