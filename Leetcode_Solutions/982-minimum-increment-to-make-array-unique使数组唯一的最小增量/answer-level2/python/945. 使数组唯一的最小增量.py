一种思路
```python []
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        i, ans = 0, 0
        for a in sorted(A):
            ans += max(i - a, 0)
            i = max(a, i) + 1
        return ans
```