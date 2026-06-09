

```python []
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        return itertools.chain(*(itertools.combinations(nums, i) for i in range(len(nums) + 1)))
```