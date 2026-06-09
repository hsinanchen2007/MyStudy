这道题很简单，通过读题不难看出要使 `min(a, b)` 的总和最大, 只需将数组递增排序后间隔求和即可。

```python
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2])
```