### 解题思路
参见题解 [主站 54 题](https://leetcode-cn.com/problems/spiral-matrix/)

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        if m == 0:
            return []
        n = len(matrix[0])
        if n == 0:
            return []
        mark = [[False]*n for _ in range(m)]
        i, j = 0, 0
        result = []
        dx, dy = [0,1,0,-1], [1,0,-1,0]
        k = 0
        while 0<=i <m and 0<=j <n and not mark[i][j]:
            mark[i][j] = True
            result.append(matrix[i][j])
            ni, nj = i+dx[k], j+dy[k]
            if 0<= ni<m and 0<=nj < n and not mark[ni][nj]:
                i, j = ni, nj
            else:
                k = (k+1)%4
                i, j = i+dx[k], j+dy[k]
        return result
```