

```python []
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        ans = []
        for i, n in zip(index, nums):
            ans[i: i] = [n]
        return ans
```