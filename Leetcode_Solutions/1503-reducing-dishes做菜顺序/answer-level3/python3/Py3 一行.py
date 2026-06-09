
一行，有一点点点损失，因为要算到底，其实可以二分找0，然后从0的位置往右。

但二分其实没有什么必要，因为排序是$O(n*lg(n))$的，因此后面的优化快还是快一些的，但意义不大。

```python []
class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        return max(accumulate(accumulate([0] + sorted(satisfaction, reverse = True))))
```
