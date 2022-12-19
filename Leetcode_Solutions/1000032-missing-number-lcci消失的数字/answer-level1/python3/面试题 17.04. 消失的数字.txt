
```python []
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return ({*range(len(nums) + 1)} - {*nums}).pop()
```