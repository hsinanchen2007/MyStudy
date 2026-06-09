采用一次二分法，要把这个数组看成两部分，左边一部分和右边一部分 模型xxxx00000这种。采用二分法先定位mid在哪个部分，然后哪nums[mid]的值与target的大小对比，然后缩小区间
```python []

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        if nums is None or len(nums)==0:
            return -1
        
        start = 0
        end = len(nums) - 1
        while start + 1 < end:
            mid = start + (end - start) // 2
            if nums[mid] == target:
                return mid
            if nums[start] < nums[mid]:
                # mid落在左边时（大数字那边）
                if nums[start] <= target and target <= nums[mid]:
                    end = mid
                else:
                    start = mid
                    
            else:  # nums[start] > nums [mid] mid落在右边
                if nums[mid] <= target and target <= nums[end]:
                    start = mid
                else:
                    end = mid
                    
        if nums[start] == target:
            return start
        if nums[end] == target:
            return end
        return -1