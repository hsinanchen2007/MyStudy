```python []
class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        l, r = [1], [1]
        for i in range(len(a)):
            l.append(l[-1] * a[i])
            r.append(r[-1] * a[~i])
        return [l[i] * r[~(i + 1)] for i in range(len(a))]
```