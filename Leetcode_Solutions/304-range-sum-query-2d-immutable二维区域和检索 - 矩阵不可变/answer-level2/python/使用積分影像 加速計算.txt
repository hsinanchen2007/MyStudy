### 解题思路
先產生積分影像 只要計算一次
而後需要的矩形範圍 總合 只要將 
右下角座標像素值 + 左上角座標像素值 - 右上座標像素值 - 左下角座標像素值就可以得到結果

### 代码

```python3
import numpy as np
class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        if len(matrix) == 0:
            self.integra = np.array((0,0))
        else:
            self.matrix = np.array(matrix)
            for i in range (1, len(matrix)):
                self.matrix[i,:] += self.matrix[i-1,:]
            for j in range (1, len(matrix[0])):
                self.matrix[:, j] += self.matrix[:,j-1]
            self.integra = np.zeros((len(matrix)+1, len(matrix[0])+1))
            self.integra[1:,1:] = self.matrix    
    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:        
        if self.integra.shape == (0,0):
            return 0
        
        row2 += 1
        col2 += 1
        res = self.integra[row2][col2] + self.integra[row1][col1] - self.integra[row1][col2] - self.integra[row2][col1]
        return int(res)


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
```