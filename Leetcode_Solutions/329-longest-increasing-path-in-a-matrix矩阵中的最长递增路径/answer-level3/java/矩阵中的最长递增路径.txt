## 总结

本文面向高阶读者者。它引入了以下概念：深度优先搜索，记忆化，动态规划和拓扑排序。本文解释了动态规划和拓扑排序的关系。

## 正文
#### 方法一：朴素的深度优先搜索 【超时】

**直觉**

深度优先搜索可以找到从任何单元格开始的最长递增路径。我们可以对全部单元格进行深度优先搜索。

**算法**

每个单元格可以看作图 $G$ 中的一个定点。若两相邻细胞的值满足 $a < b$，则存在有向边 $(a, b)$。问题转化成：

> 寻找有向图 $G$ 中的最长路径。

很显然,我们可以使用深度优先搜索或广度优先搜索从根开始访问连接的所有细胞。在搜索期间更新路径的最大长度，并在搜索完成后得到答案。

一般而言，在深度优先搜索或广度优先搜索中，我们可以使用集合`visited` 来避免重复访问。在下一节中我们将介绍基于此的更优算法。

```Java [solution 1]
// Naive DFS Solution
// Time Limit Exceeded
public class Solution {
  private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  private int m, n;

  public int longestIncreasingPath(int[][] matrix) {
      if (matrix.length == 0) return 0;
      m = matrix.length;
      n = matrix[0].length;
      int ans = 0;
      for (int i = 0; i < m; ++i)
          for (int j = 0; j < n; ++j)
              ans = Math.max(ans, dfs(matrix, i, j));
      return ans;
  }

  private int dfs(int[][] matrix, int i, int j) {
      int ans = 0;
      for (int[] d : dirs) {
          int x = i + d[0], y = j + d[1];
          if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j])
              ans = Math.max(ans, dfs(matrix, x, y));
      }
      return ++ans;
  }
}
```

**复杂度分析**

* 时间复杂度 ：$O(2^{m+n})$。对每个有效递增路径均进行搜索。在最坏情况下，会有 $O(2^{m+n})$ 次调用。例如：

```
1 2 3 . . . n
2 3 . . .   n+1
3 . . .     n+2
.           .
.           .
.           .
m m+1 . . . n+m-1
```


* 空间复杂度 ： $O(mn)$。 对于每次深度优先搜索，系统栈需要 $O(h)$ 空间，其中 $h$ 为递归的最深深度。最坏情况下， $O(h) = O(mn)$。

---
#### 解法二：记忆化深度优先搜索 【通过】
**直觉**

将递归的结果存储下来，这样每个子问题只需要计算一次。

**算法**

从上面的分析中，我们知道在淳朴的深度优先搜索方法中有许多重复的计算。

一个优化途径是我们可以用一个集合来避免一次深度优先搜索中的重复访问。该优化可以将一次深度优先搜索的时间复杂度优化到 $O(mn)$，总时间复杂度 $O(m^2n^2)$。

下面介绍一个更有力的优化方法，记忆化。
> 在计算中，记忆化是一种优化技术，它通过存储“昂贵”的函数调用的结果，在相同的输入再次出现时返回缓存的结果，以此加快程序的速度。

在本问题中，我们多次递归调用 `dfs(x, y)` 。但是，如果我们已经知道四个相邻单元格的结果，就只需要常数时间。在搜索过程中，如果未计算过单元格的结果，我们会计算并将其缓存；否则，直接从缓存中获取之。

```Java [solution 3]
// DFS + Memoization Solution
// Accepted and Recommended
public class Solution {
    private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    private int m, n;

    public int longestIncreasingPath(int[][] matrix) {
        if (matrix.length == 0) return 0;
        m = matrix.length; n = matrix[0].length;
        int[][] cache = new int[m][n];
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans = Math.max(ans, dfs(matrix, i, j, cache));
        return ans;
    }

    private int dfs(int[][] matrix, int i, int j, int[][] cache) {
        if (cache[i][j] != 0) return cache[i][j];
        for (int[] d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j])
                cache[i][j] = Math.max(cache[i][j], dfs(matrix, x, y, cache));
        }
        return ++cache[i][j];
    }
}
```

**复杂度分析**

* 时间复杂度 : $O(mn)$。 每个顶点/单元格均计算一次，且只被计算一次。每条边也均计算一次并只计算一次。总时间复杂度是 $O(V+E)$。$V$ 是顶点总数，$E$ 是边总数。本问题中，$O(V) = O(mn)$，$O(E) = O(4V) = O(mn)$。

* 空间复杂度 : $O(mn)$。缓存决定了空间复杂度。

---
#### 方法三：“剥洋葱”（动态规划） 【通过】

**直觉**

每个细胞的结果只与相邻的结果相关，能否使用动态规划？

**算法**
如果我们定义从单元格 $(i, j)$ 开始的最长递增路径为函数
$$
f(i, j)
$$

则可以写出状态转移函数

$$
f(i, j) = max\{f(x, y)| (x, y)~\mathrm{is~a~nei***or~of} (i, j)~\mathrm{and} ~\mathrm{matrix}[x][y] \gt \mathrm{matrix}[i][j]\} + 1
$$

此公式与以前方法中使用的公式相同。有了状态转移函数，你可能会觉得可以使用动态规划来推导出所有结果，去他的深度优先搜索!

这听起来很美好，可惜你忽略了一件事：我们没有依赖列表。

想要让动态规划有效，如果问题 B 依赖于问题 A 的结果，就必须确保问题 A 比问题 B先计算。这样的依赖顺序对许多问题十分简单自然。如著名的斐波那契数列：

$$
F(0) = 1, F(1) = 1, F(n) = F(n - 1) + F(n - 2)
$$

子问题 $F(n)$ 依赖于 $F(n - 1)$ 和 $F(n - 2)$。因此，自然顺序就是正确的计算顺序。被依赖者总会先被计算。

这种依赖顺序的术语是“拓扑顺序”或“拓扑排序”：

> 对有向无环图的拓扑排序是顶点的一个线性排序，使得对于任何有向边 $(u, v)$，顶点 $u$ 都在 顶点 $v$ 的前面。 

在本问题中，拓扑顺序并不简单自然。没有矩阵的值，我们无法知道两个邻居 A 和 B 的依赖关系。作为预处理，我们必须显式执行拓扑排序。之后，我们可以按照存储的拓扑顺序使用状态转移函数动态地解决问题。

有多种实现拓扑排序的方法。这里我们使用的是一种被称为“剥洋葱”的方法。其思路是在一个有向无环图中，会有一些不依赖于其他顶点的顶点，称为“叶子”。我们将这些叶子放在一个列表中（他们的内部排序不重要），然后将他们从图中移除。移除之后，会产生新的“叶子”。重复以上过程，就像一层一层一层地拨开洋葱的心。最后，列表中就会存储有效的拓扑排序。

在本问题中，因为我们想要求出在整个图中最长的路径，也就是“洋葱”的层总数。因此，我们可以在“剥离”的期间计算层数，在不调用动态规划的情况下返回计数。

```Java [solution 3]
// Topological Sort Based Solution
// An Alternative Solution
public class Solution {
    private static final int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    private int m, n;
    public int longestIncreasingPath(int[][] grid) {
        int m = grid.length;
        if (m == 0) return 0;
        int n = grid[0].length;
        // padding the matrix with zero as boundaries
        // assuming all positive integer, otherwise use INT_MIN as boundaries
        int[][] matrix = new int[m + 2][n + 2];
        for (int i = 0; i < m; ++i)
            System.arraycopy(grid[i], 0, matrix[i + 1], 1, n);

        // calculate outdegrees
        int[][] outdegree = new int[m + 2][n + 2];
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                for (int[] d: dir)
                    if (matrix[i][j] < matrix[i + d[0]][j + d[1]])
                        outdegree[i][j]++;

        // find leaves who have zero out degree as the initial level
        n += 2;
        m += 2;
        List<int[]> leaves = new ArrayList<>();
        for (int i = 1; i < m - 1; ++i)
            for (int j = 1; j < n - 1; ++j)
                if (outdegree[i][j] == 0) leaves.add(new int[]{i, j});

        // remove leaves level by level in topological order
        int height = 0;
        while (!leaves.isEmpty()) {
            height++;
            List<int[]> newLeaves = new ArrayList<>();
            for (int[] node : leaves) {
                for (int[] d:dir) {
                    int x = node[0] + d[0], y = node[1] + d[1];
                    if (matrix[node[0]][node[1]] > matrix[x][y])
                        if (--outdegree[x][y] == 0)
                            newLeaves.add(new int[]{x, y});
                }
            }
            leaves = newLeaves;
        }
        return height;
    }
}
```



**复杂度分析**

* 时间复杂度 : $O(mn)$。拓扑排序的时间复杂度为 $O(V+E) = O(mn)$。$V$ 是顶点总数，$E$ 是边总数。本问题中，$O(V) = O(mn)$，$O(E) = O(4V) = O(mn)$。


* 空间复杂度 : $O(mn)$。我们需要存储出度和每层的叶子。
## 要点

* 记忆化: 对于大量重复调用的问题，缓存其结果。
* 动态规划要求按照拓扑顺序解决子问题。对于很多问题，拓扑顺序与自然秩序一致。而对于那些并非如此的问题，需要首先执行拓扑排序。因此,对于复杂拓扑问题（如本题），使用记忆化搜索通常是更容易更好的选择。
