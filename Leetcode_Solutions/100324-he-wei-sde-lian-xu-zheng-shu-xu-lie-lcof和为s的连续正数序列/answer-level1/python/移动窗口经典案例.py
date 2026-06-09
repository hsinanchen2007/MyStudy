
### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        i = 1
        j = 1
        s = 0
        res = []
        while i <= target // 2:
            if s < target:
                s += j
                j += 1
            elif s > target:
                s -= i
                i += 1
            else:
                res.append(list(range(i, j)))
                s -= i
                i += 1
        return res

```