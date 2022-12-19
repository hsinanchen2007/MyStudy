
```python []
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return bisect.bisect(nums, target) - bisect.bisect_left(nums, target)
```