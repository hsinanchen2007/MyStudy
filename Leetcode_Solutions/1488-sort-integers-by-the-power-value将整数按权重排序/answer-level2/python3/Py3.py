把跑过的值缓存一下就行
Python的sort和sorted是稳定排序，因此不需要额外的比较
```python3 []
class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        from functools import lru_cache
        @lru_cache(None)
        def F(n):
            if n == 1: return 0
            return F(n * 3 + 1) + 1 if n % 2 else F(n // 2) + 1 
        return sorted(range(lo, hi + 1), key = F)[k - 1]
```
最后一句这样好像也可以，k比较小时更快
不过我不清楚heapq.nsmallest的排序是不是稳定的，但可以过
```python3
return heapq.nsmallest(k, range(lo, hi + 1), key = F)[-1]
```
