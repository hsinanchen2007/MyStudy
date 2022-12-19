```python
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        for i in range(1, target // 2 + 1):
            n = 0
            while True:
                if (2 * i + n - 1) * n == target * 2:
                    res.append(list(range(i, i + n)))
                    break
                elif (2 * i + n) * n > target * 2:
                    break
                else:
                    n += 1
                    continue 
        return res
```
