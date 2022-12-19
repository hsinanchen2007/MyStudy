```python []
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        return [[]] if not nums else [[x for j, x in enumerate(nums) if i & (1 << j)] for i in range(2 ** len(nums))]
```
