比较排序前后的元素是否相等，利用 `sum([true])` 进行计数

```python
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        return sum(a != b for a,b in zip(sorted(heights), heights))
```
