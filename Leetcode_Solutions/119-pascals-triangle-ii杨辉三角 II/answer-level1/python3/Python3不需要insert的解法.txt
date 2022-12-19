击败99.55%的解法, 不需要insert方法

```python
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex < 2:
            return [1] * (rowIndex + 1)
        res = [1, 1]
        for i in range(2, rowIndex+1):
            for j in range(i - 1, 0, -1):
                res[j] = res[j-1] + res[j]
            res.append(1)
        return res
        
```