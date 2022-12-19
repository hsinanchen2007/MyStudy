![image.png](https://pic.leetcode-cn.com/5d106bd5c2d9b311b25ef238ff8e4147fb60abfc5cdd181e9754e14c85648536-image.png)

164ms仅供参考，也算再扩数据后的分布最左边了。

把全局计数放进列表，就不用`self`或`nonlocal`全局声明了，迭代器用了`itertools.product`，已经是最大优化了。

时间复杂度$O(RC)$

```python []
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ans, r, c = [0, 0], len(grid), len(grid[0])
        def f(i, j):
            ans[1] += 1
            grid[i][j] = 0
            for x, y in [(i + 1, j),(i - 1, j),(i, j + 1),(i, j - 1)]:
                if 0 <= x < r and 0 <= y < c and grid[x][y]:
                    f(x, y)
        for i, j in itertools.product(range(r), range(c)):
            if grid[i][j]:
                ans[1] = 0
                f(i, j)
                ans[0] = max(ans)
        return ans[0]
```
