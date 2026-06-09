### 解题思路
此处撰写解题思路
相当于多个数组求和叠加
### 代码

```python3
class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.matrix=matrix

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        sumr=0
        for i in range(row1,row2+1):
            sumr+=sum(self.matrix[i][col1:col2+1])
        return sumr
            
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
```