```
class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        res = [cont[-1], 1]
        for i in range(len(cont) - 1, 0, -1):
            res[0], res[1] = res[1], res[0]
            res[0] += cont[i-1] * res[1]
        return res
```
