**思路：**

从大到小枚举可能的边长，最大的边长为 `min(grid, grid[0])`，然后枚举起始坐标，检查以起始坐标为左上端点的、并且以 $1$ 为界的正方形是否存在。如果我们直接检查正方形的边界是否都为 $1$，那么总的时间复杂度会达到 $O(N^4)$，所以我们需要在检查边长的时候做一些优化，避免重复检查矩阵元素是否为 $1$。用前缀和的方法可以达到这个效果。我们用 `L[i][j]` 表示 `(i, j)` 的左边有多少个 $1$，用 `U[i][j]` 表示 `(i, j)` 的上边有多少个 $1$，那么我们就可以计算一条边两个端点的差值，看看这个差值是否和边的长度相等就可以了。优化后的时间复杂度降为 $O(N^3)$。

**图解：**

![边界符合条件的检查过程](https://pic.leetcode-cn.com/839c25d4e013aa007a06707e0c7dad4874ad5a4510c3978f8ee7c00eccc05c9c.gif){:width=600}
{:align=center}


**代码：**
```python [Python]
class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        # 矩阵规模
        n, m, s = len(grid), len(grid[0]), 0
        # 四个方向上的前缀和
        L, U = [[[0] * (m + 1) for i in range(n + 1)] for j in range(2)]
        for i in range(n):
            for j in range(m):
                # 矩阵和
                s += grid[i][j]
                # L[i][j] 表示 (i, j) 的左边有多少个 1
                L[i][j + 1] = L[i][j] + grid[i][j]
                # U[i][j] 表示 (i, j) 的上边有多少个 1
                U[i + 1][j] = U[i][j] + grid[i][j]
        if s == 0:
            return 0
        # 四条边上 1 的个数
        edges = [0, 0, 0, 0]
        for e in range(min(n, m), 0, -1):
            for i in range(n - e + 1):
                for j in range(m - e + 1):
                    # 判断上边
                    edges[0] = L[i][j + e] - L[i][j]
                    # 判断下边
                    edges[1] = L[i + e - 1][j + e] - L[i + e - 1][j]
                    # 判断左边
                    edges[2] = U[i + e][j] - U[i][j]
                    # 判断右边
                    edges[3] = U[i + e][j + e - 1] - U[i][j + e - 1]
                    # 判断是否满足
                    if all([edge == e for edge in edges]):
                        return e * e
        return 0
```
