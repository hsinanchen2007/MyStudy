### 解题思路
此处撰写解题思路
给外部的矩阵加一个框

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]: return []

        ny = len(matrix)
        nx = len(matrix[0])
        #路径矩阵，加一个外壳，表示边界
        path = [[0] * (nx + 2) for _ in range(ny + 2)]

        for x in range(nx + 2):
            path[0][x] = 1
            path[-1][x] = 1

        for y in range(ny + 2):
            path[y][0] = 1
            path[y][-1] = 1
        #四个方向
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        next_x, next_y = 0, 1

        ret = []
        i = 0
        cnt = 0
        while cnt < nx * ny:
            while path[next_y + dirs[i][1]][next_x + dirs[i][0]] == 0:
                next_x, next_y = next_x + dirs[i][0], next_y + dirs[i][1]
                path[next_y][next_x] = 1
                cnt += 1
                #添加元素
                ret.append(matrix[next_y - 1][next_x - 1])
            i = (i + 1) % len(dirs)

        return ret
```

