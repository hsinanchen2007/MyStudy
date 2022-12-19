### 解题思路

线性定义街道的连通性, 假设上下左右分别为`[1, 2, 0, 3]`, 那么题目给出的六个街道分别对应`memo = [(), (0, 3), (1, 2), (0, 2), (2, 3), (0, 1), (1, 3)]`, 第一元素为空是为了下标一一对应

一个街道有入口和出口, 假设上一个街道的出口为`out`, 那么它可以进入该街道的条件为, 当前街道有一个与其向对应入口, 按照方向的定义, 该入口应为 `3-out`.否则无法进入该节点, 那么该街道的出口就为剩下的那个出入口.

如果一个街道的出口为`out`, 那么他的下一个街道的坐标因为该出口连接的下一个街道, 其坐标与当前坐标差是:` dir = [(0, -1), (-1, 0), (1, 0), (0, 1)]`

具体流程见代码

### 代码

```python
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        memo = [(), (0, 3), (1, 2), (0, 2), (2, 3), (0, 1), (1, 3)]
        dir = [(0, -1), (-1, 0), (1, 0), (0, 1)]
        m, n = len(grid), len(grid[0])
        def path(x, y, come):
            while True:
                if x < 0 or x == m or y < 0 or y == n: return False # 该节点在范围外
                d = memo[grid[x][y]]
                if come + d[0] == 3 or come + d[1] == 3: # 该街道是否可以到达
                    if (x, y) == (m - 1, n - 1): return True
                    out = come + d[0] + d[1] - 3
                    # print(x, y, come, xi)
                    x, y = x + dir[out][0], y + dir[out][1] # 下一街道坐标
                    come = out # 当前出口, 为下一街道入口
                else: return False
            return False
        y = path(0, 0, 0) or path(0, 0, 1) or path(0, 0, 2) or path(0, 0, 3) # 可以从任意一个方向进入街道(0, 0)
    
        return y
```