这题像脑筋急转弯一样，想到了就能做，想不到就做不出来
就是只要披萨不相邻，那总有一种办法可以取到，不过我不会证这个，就给一份Python代码吧

```python3 []
class Solution:
    def maxSizeSlices(self, slices: List[int]) -> int:
        l = len(slices)
        from functools import lru_cache
        @lru_cache(None)
        def T(i, n, last):
            if n == 0 or i >= l - last: return 0
            return max(T(i + 2, n - 1, last) + slices[i], T(i + 1, n, last))
        return max(T(2, l // 3 - 1, 1) + slices[0], T(1, l // 3, 0))
```
