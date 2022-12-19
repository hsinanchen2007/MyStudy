直接系统函数`Counter`出所有值的数量，然后把`key`进行排序，再按条件筛选计算出最大值。

```python []
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        d = collections.Counter(nums)
        a = sorted(d)
        return max([0] + [d[a[i]] + d[a[i - 1]] for i in range(1, len(a)) if a[i] == a[i - 1] + 1])
```
