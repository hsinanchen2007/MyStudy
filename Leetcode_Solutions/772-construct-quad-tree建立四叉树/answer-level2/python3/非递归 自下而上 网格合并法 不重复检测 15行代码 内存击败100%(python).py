核心思想：每次处理一个四方块，有2种情况。
1）如果值都是int类型而且值都一样 -> 叶子节点 （还是用int，简化比较逻辑）
2）否则：合并这4个节点，生成一个中间节点。

```
class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def leaf(v):
            return Node(bool(v), True, *[None] * 4)

        def quad(grid, i, j):
            si, sj = 2 * i, 2 * j  # 行和列的开始坐标
            vs = grid[si][sj:sj + 2] + grid[si + 1][sj:sj + 2]  # 子节点：上下左右，类型：int和Node混合
            if vs[0:3] == vs[1:4] and isinstance(vs[0], int):  # 叶子节点： 全部相同而且都是整数
                return vs[0]  # 用int表示叶子节点，优化空间和比较逻辑
            vs = [leaf(v) if isinstance(v, int) else v for v in vs]  # int变成叶子节点
            return Node('*', False, *vs)

        while len(grid) > 1:
            n = len(grid) >> 1  # 每次每行（列）考虑2个格子，因此规模减半
            grid = [[quad(grid, i, j) for j in range(n)] for i in range(n)]  # 新的网格

        v = grid[0][0]  # 最后的节点
        return leaf(v) if isinstance(v, int) else v  # 整数表示叶子节点
```


![Screen Shot 2019-10-17 at 6.03.05 PM.png](https://pic.leetcode-cn.com/6bf282817e4d6d9f50d9e32ae93630a3fa125cda2a887a63cfdd9dacff0a3ecc-Screen%20Shot%202019-10-17%20at%206.03.05%20PM.png)
