俺用的方法是在右边和下面加一圈[0]，下标运算也比较直接。

```
class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.d=matrix
        m=len(self.d)
        if m>0:
            n=len(self.d[0])
            self.d+=[[0]*(n+1)]
        for i in range(m):
            self.d[i]+=[0]
            for j in range(n):
                self.d[i][j]+=self.d[i-1][j]+self.d[i][j-1]-self.d[i-1][j-1]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.d[row2][col2]-self.d[row2][col1-1]-self.d[row1-1][col2]+self.d[row1-1][col1-1]
```
