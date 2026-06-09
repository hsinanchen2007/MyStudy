思路就是最经典的最大化最小值二分，给一份python的代码
```python
class Solution:
    def maximizeSweetness(self, sweetness: List[int], K: int) -> int:
        def judge(x):
            k, s = K, 0
            for i in sweetness:
                s += i
                if s >= x:
                    s, k = 0, k - 1
            return k < 0
        
        lo, hi = 1, sum(sweetness) // (K + 1) + 1
        while lo != hi - 1:
            t = (lo + hi) // 2
            if judge(t):
                lo = t
            else:
                hi = t
        return lo
```
