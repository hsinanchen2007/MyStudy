### 解题思路
在矩阵外围嵌套一个0环。这样就可以节省限制条件

### 代码

```python3
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        sum = 0
        k = len(grid)
        l = len(grid[0])
        T = [] * (k+2)
        T.append([0] * (l+2))
        for i in range(k):
            T.append([0] + grid[i] + [0])
        T.append([0] * (l+2))
        for i in range(1,k+1):
            for j in range(1,l+1):
                if T[i][j] == 1:
                    t = 4
                    if T[i][j-1] == 1:
                        t -= 1
                    if T[i][j+1] == 1:
                        t -= 1
                    if T[i+1][j] == 1:
                        t -= 1
                    if T[i-1][j] == 1:
                        t -= 1
                else:
                    t = 0
                sum += t 
        return sum



```