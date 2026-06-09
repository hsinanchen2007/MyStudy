### 解题思路
难点在于首行首列制0，但是不能影响后续其他行的判断。所以用两个标记，最后来处理首行首列

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row_flag = False
        line_flag = False
        for x, y in [(x, y) for x in range(len(matrix)) for y in range(len(matrix[0]))]:

            if matrix[x][y] == 0:
                if x == 0 and not row_flag:
                    row_flag = True #第一行发现了0，最后需要制空第一行
                if y == 0 and not line_flag:
                    line_flag = True #第一列发现了0，最后需要制空第一行
                matrix[x][0] = 0
                matrix[0][y] = 0

        for x, y in [(x, y) for x in range(len(matrix)) for y in range(len(matrix[0])) if matrix[x][0] == 0 or matrix[0][y] == 0]:
            # 暂时不能改第一行第一列，不然会影响判断
            if x > 0 and y > 0:
                matrix[x][y] = 0

        # 修改第一行第一列
        if row_flag:
            for y in range(len(matrix[0])):
                matrix[0][y] = 0
        if line_flag:
            for x in range(len(matrix)):
                matrix[x][0] = 0
```