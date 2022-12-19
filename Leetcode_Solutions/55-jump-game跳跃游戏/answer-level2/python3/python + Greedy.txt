```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if nums == []: return True
        end = nums[0]
        for i, num in enumerate(nums):
            if i > end: return False
            end = max(i + num, end)
        return True
```