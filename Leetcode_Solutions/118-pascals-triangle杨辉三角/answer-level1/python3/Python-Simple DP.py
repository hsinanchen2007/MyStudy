```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        tmp = []
        for _ in range(numRows):
            tmp.insert(0, 1)
            for i in range(1, len(tmp) - 1):
                tmp[i] = tmp[i] + tmp[i+1]
            res.append(tmp[:])
        return res
```
