### 解题思路
这道题难点在于如何标记有0的那行那列。下面的代码是官方题解的第三种思路，行首列首置0来标记是否要将该行该列置0，不过第一行与第一列比较特殊，需要单独讨论。

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        cols = len(matrix[0])
        first_row = False
        first_col = False
        # 检查第一行与第一列
        for i in range(rows):
            if matrix[i][0]==0:
                first_row=True
                break
        for j in range(cols):
            if matrix[0][j]==0:
                first_col=True
                break
        # 找到有0的那行那列，并用0填充行首与列首
        for i in range(1,rows):
            for j in range(1,cols):
                if matrix[i][j]==0:
                    matrix[i][0]=0
                    matrix[0][j]=0
        # 置0
        for i in range(1,rows):
            if matrix[i][0]==0:
                for j in range(1,cols):
                    matrix[i][j]=0
        for j in range(1,cols):
            if matrix[0][j]==0:
                for i in range(1,rows):
                    matrix[i][j]=0
        # 检查第一行与第一列
        if first_row:
            for i in range(rows):
                matrix[i][0]=0
        if first_col:
            for j in range(cols):
                matrix[0][j]=0
```