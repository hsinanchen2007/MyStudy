### 解题思路
用set获取matrix中0元素的行，列坐标（用set是因为可以自动去重）
对于所有的行进行分析
    ----若该行有0元素，直接全行置0，不对列作分析
    ----若该行没有0元素，对于有0的列进行置0

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
       #出现0的行列
        row = len(matrix)
        col = len(matrix[0])
        z_row={i for i in range(row) for j in range(col) if matrix[i][j]==0}
        z_col={j for i in range(row) for j in range(col) if matrix[i][j]==0}

        for i in range(row):
            if i in z_row:
                matrix[i] = col*[0]
                continue
            for j in z_col:
                matrix[i][j]=0
        

```