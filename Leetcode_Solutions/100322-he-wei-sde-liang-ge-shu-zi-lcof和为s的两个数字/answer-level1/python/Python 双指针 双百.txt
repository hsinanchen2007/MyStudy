```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return nums
        
        small, large = 0, len(nums)-1

        while small<large:
            if nums[small] + nums[large] < target:
                small += 1
            elif nums[small] + nums[large] > target:
                large -= 1
            elif nums[small] + nums[large] == target:
                return [nums[small], nums[large]]
        
        return None
```
