### 解题思路
这一题很像 [463. 岛屿的周长](https://leetcode-cn.com/problems/island-perimeter/)


这里一个立方体有 6个面，底面和顶面不会被遮挡，主要考虑前后左右四个面，
如果前面上没有立方体，那么就多了立方体的高度个面，如果有，就考虑遮挡了多少，然后计算即可。

#### 官方题解和我的思路一样，不过加了些语法糖，写得更清晰，例如 count += max(a,-b, 0)

另有一些解法使用 总可能的表面积 - 被遮挡住的表面积
我有些理解不透。


### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        dx, dy = [1,-1,0,0], [0,0,1,-1]
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] != 0:
                    count = 0
                    # 顶部和底部：
                    count += 2
                    # 四个面
                    for k in range(4):
                        nx, ny = i+dx[k], j+dy[k]
                        if not (0<=nx<m) or not (0<=ny<n) or grid[nx][ny] == 0:
                            count += grid[i][j]
                        else:
                            if grid[i][j] > grid[nx][ny]:
                                count += (grid[i][j]-grid[nx][ny])
                # res += count 缩进位置不对导致 bug
                    res += count
        return res


```