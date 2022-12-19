### 解题思路
暴力解法，提供一个不一样的思路，哈哈
每个小立方体有6个面，每个面可以用中心点坐标唯一表示出来，坐标相同的表示同一个面，删掉后数一下
### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        l = [(0.5, 0, 0), (0, 0, -0.5), (-0.5, 0, 0),
             (0, 0, 0.5), (0, -0.5, 0), (0, 0.5, 0)]

        face = {}
        N = len(grid)
        for i in range(N):
            for j in range(N):
                for k in range(grid[i][j]):
                    for f in l:
                        t = (f[0] + i, f[1] + j, f[2] + k)
                        if t not in face:
                            face[t] = 0
                        else:
                            face.pop(t)
        return len(face)
```