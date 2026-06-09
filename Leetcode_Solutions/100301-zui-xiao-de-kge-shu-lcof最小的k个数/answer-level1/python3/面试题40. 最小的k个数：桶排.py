```python []
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        ans, d = [], [0] * 10001
        for i in arr:
            d[i] += 1
        for i, j in enumerate(d):
            if j:
                c = min(k, j)
                ans.extend([i] * c)
                k -= j
                if k <= 0:
                    break
        return ans
```
