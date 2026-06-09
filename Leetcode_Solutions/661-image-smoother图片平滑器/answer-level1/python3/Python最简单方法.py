### 解题思路
依次计算矩阵中的每个元素的平均灰度，筛选合法下标计算。

### 代码

```python3
class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        row, col = len(M), len(M[0])
        res = [[0 for _ in range(col)] for __ in range(row)]

        def calc(x, y):
            n = 0
            s = 0
            steps = [[0, 0], [1, 0], [1, 1], [0, 1], [-1, 1],
                    [-1, 0], [-1, -1], [0, -1], [1, -1]]
            for i in steps:
                dx = x + i[0]
                dy = y + i[1]
                if 0 <= dx < row and 0 <= dy < col:
                    n += 1
                    s += M[dx][dy]
            return s // n
        
        for i in range(row):
            for j in range(col):
                res[i][j] = calc(i, j)
        return res
```