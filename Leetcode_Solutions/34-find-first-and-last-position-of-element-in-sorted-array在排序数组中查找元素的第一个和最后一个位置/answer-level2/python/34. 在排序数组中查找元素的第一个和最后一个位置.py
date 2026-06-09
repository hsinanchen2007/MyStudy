```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums or len(nums) == 0:
            return [-1, -1]
        left, right = -1, -1

        # left bounder
        start, end = 0, len(nums) - 1
        while start + 1 < end:
            mid = start + ((end - start) >> 1)
            if target <= nums[mid]:
                end = mid
            else:
                start = mid
        if target == nums[end]:
            left = end
        if target == nums[start]:
            left = start
        
        # right bounder
        start, end = 0, len(nums) - 1
        while start + 1 < end:
            mid = start + ((end - start) >> 1)
            if target >= nums[mid]:
                start = mid
            else:
                end = mid
        if target == nums[start]:
            right = start
        if target == nums[end]:
            right = end
        
        return [left, right]
```