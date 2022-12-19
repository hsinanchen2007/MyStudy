```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxArrived = 0
        for i, num in enumerate(nums):
            if i <= maxArrived:
                if i + num >= len(nums) - 1: return True
                maxArrived = max(maxArrived, i + num)
            else: return False
```