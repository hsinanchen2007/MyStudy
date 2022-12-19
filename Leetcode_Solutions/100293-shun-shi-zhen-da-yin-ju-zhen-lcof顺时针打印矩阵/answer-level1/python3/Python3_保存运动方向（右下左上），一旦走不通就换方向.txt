### 解题思路
从最开始，遍历的顺序是右下左上。如果当前方向走得通就一直走，不通就换方向。
走过的要记录。

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        dir_idx = 0
        dir = directions[dir_idx]
        m, n = len(matrix), len(matrix[0])
        total = m * n
        res = []
        i, j = 0, 0
        while len(res) < total:
            res.append(matrix[i][j])
            matrix[i][j] = '/'
            next_i, next_j = i + dir[0], j + dir[1]
            if 0 <= next_i < m and 0 <= next_j < n and matrix[next_i][next_j] != '/':
                i = next_i
                j = next_j
            else:
                dir_idx += 1
                if dir_idx == len(directions):
                    dir_idx = 0
                dir = directions[dir_idx]
                i = i + dir[0]
                j = j + dir[1]
        return res
```