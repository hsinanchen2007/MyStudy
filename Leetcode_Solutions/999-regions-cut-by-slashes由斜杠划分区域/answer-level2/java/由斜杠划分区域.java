#### 方法 1：并查集

**想法**

为了找到图中连通块的数量，我们可以使用深度优先搜索或者并查集算法。问题的难点在于如何识别出整张图。

一个“暴力”的识图方法是将每个正方形网格看成四个顶点（东、南、西、北），表示存在两条斜杠时，正方形网格被划分成的四个三角形。然后，将四个顶点连接如果正方形网格是 `" "`，两两连接如果网格是 `"/"` 或者 `"\"`。最终，我们可以连接所有相邻的顶点（例如，正方形网格 `grid[0][0]` 的东节点和 `grid[0][1]` 的西节点相连）。

这是最直接的方法，也存在其他方法可以用更少的节点来表示相连信息。

**算法**

创建 `4*N*N` 个顶点，每个代表一个三角形，按照如上的方式连接它们。然后，使用并查集算法找到连通块的总数。

在此，我们跳过如何利用并查集的实现，可以参考 [https://leetcode.com/problems/redundant-connection/solution/](https://leetcode.com/problems/redundant-connection/solution/)  了解实现方法。

```Java []
class Solution {
    public int regionsBySlashes(String[] grid) {
        int N = grid.length;
        DSU dsu = new DSU(4 * N * N);
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c) {
                int root = 4 * (r * N + c);
                char val = grid[r].charAt(c);
                if (val != '\\') {
                    dsu.union(root + 0, root + 1);
                    dsu.union(root + 2, root + 3);
                }
                if (val != '/') {
                    dsu.union(root + 0, root + 2);
                    dsu.union(root + 1, root + 3);
                }

                // north south
                if (r + 1 < N)
                    dsu.union(root + 3, (root + 4 * N) + 0);
                if (r - 1 >= 0)
                    dsu.union(root + 0, (root - 4 * N) + 3);
                // east west
                if (c + 1 < N)
                    dsu.union(root + 2, (root + 4) + 1);
                if (c - 1 >= 0)
                    dsu.union(root + 1, (root - 4) + 2);
            }

        int ans = 0;
        for (int x = 0; x < 4 * N * N; ++x) {
            if (dsu.find(x) == x)
                ans++;
        }

        return ans;
    }
}

class DSU {
    int[] parent;
    public DSU(int N) {
        parent = new int[N];
        for (int i = 0; i < N; ++i)
            parent[i] = i;
    }
    public int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    public void union(int x, int y) {
        parent[find(x)] = find(y);
    }
}
```

```Python []
class DSU:
    def __init__(self, N):
        self.p = range(N)

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        self.p[xr] = yr

class Solution(object):
    def regionsBySlashes(self, grid):
        N = len(grid)
        dsu = DSU(4 * N * N)
        for r, row in enumerate(grid):
            for c, val in enumerate(row):
                root = 4 * (r*N + c)
                if val in '/ ':
                    dsu.union(root + 0, root + 1)
                    dsu.union(root + 2, root + 3)
                if val in '\ ':
                    dsu.union(root + 0, root + 2)
                    dsu.union(root + 1, root + 3)

                # north/south
                if r+1 < N: dsu.union(root + 3, (root+4*N) + 0)
                if r-1 >= 0: dsu.union(root + 0, (root-4*N) + 3)
                # east/west
                if c+1 < N: dsu.union(root + 2, (root+4) + 1)
                if c-1 >= 0: dsu.union(root + 1, (root-4) + 2)

        return sum(dsu.find(x) == x for x in xrange(4*N*N))
```

**复杂度分析**

* 时间复杂度：$O(N * N * \alpha(N))$，其中 $N$ 是网格的长度，$\alpha$ 是阿克曼逆函数（如果我们使用按排名的并查集算法）
* 空间复杂度：$O(N*N)$。