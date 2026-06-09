```python 
class Solution:
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
        res = [0] * length
        for a, b, inc in updates:
            res[a] += inc
            if b < length - 1:
                res[b + 1] -= inc
        for i in range(length):
            if i > 0: res[i] += res[i - 1]
        return res
```