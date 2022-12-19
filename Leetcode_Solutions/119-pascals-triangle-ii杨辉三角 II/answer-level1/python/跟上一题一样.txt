### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res=[[1 for j in range(i)] for i in range(1,rowIndex+2)]
        for n in range(2,rowIndex+1):
            for m in range(1,n):
                res[n][m]=res[n-1][m-1]+res[n-1][m]
        return res[rowIndex]
```