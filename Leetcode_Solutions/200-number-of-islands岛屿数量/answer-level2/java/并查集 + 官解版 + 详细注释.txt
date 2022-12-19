## 1. 并查集（Union-Find）是什么
简单来说，**并查集（Union-Find）是一种树型的数据结构，用于处理一些不相交集合（Disjoint Sets）的合并及查询问题。常常在使用中以森林来表示。**
![image.png](https://pic.leetcode-cn.com/9c0923a4b9f08367e14397ad959b7777d7f6373099d2a47badf8282543cd4367-image.png)
  

**并查集的数据结构**
![image.png](https://pic.leetcode-cn.com/079b6c7fc044e568d207a52c08554df8e275a01981205782a971ad441bf1e787-image.png)

**对于并查集结构里的元素和元素之间的连接关系，使用数组来保存。其中，有两种基本的算法来保存元素的连接关系。**

**Quick-find：**
数组表示下图中的并集关系。其中元素的值代表组别，值相同，元素的组别相同。
![image.png](https://pic.leetcode-cn.com/377c7634e2e975be08bca819916d6c09521f9626c86556e90929d909477a74a0-image.png)

**Quick-union（官解方法，后面会详解）:**
和quick-find不同的是，quick-union算法中数组元素的值代表的是根节点的id，以树的方式储存。
![image.png](https://pic.leetcode-cn.com/79a122b2df6772f3aca4484f4731b1d185e6dcedfdc9d7e6f98dc78fa05da3ae-image.png)

其实，Quick-find和Quick-union算法都不算是最高效的算法，如果有兴趣的小伙伴可以计算一下两种算法的union和find的时间/空间复杂度。不过，基于这两种算法的优化版，则可以达到logN级别的复杂度。主要的方法有三种，**带权重的QU（weighted QU）** 和 **路径压缩QU（QU + path compression）** 及 **带权重的路径压缩QU（weighted QU + path compression）.**

![image.png](https://pic.leetcode-cn.com/ddfcb1a8522ba6d09a77af9eec141933c76a0ffe9b46c5d9ceb973eb6dddc189-image.png)

对于这几种算法数据结构，实现和复杂度分析感兴趣的小伙伴，可以去看看普林斯顿大学在coursera开设的[Algorithms](https://www.coursera.org/learn/algorithms-part1/home/welcome)课程（第一周课程内容），强烈建议学习（学习时间1.5h），你会对并查集有更系统的认识。

## 官解思路：

官解使用的是**带权重的QU路径压缩（weighted QU + path compression）** 算法。 
关于带权重的QU和不带权重的QU有什么区别，感兴趣的小伙伴自己去摸索哦。

对于本问题，小岛则代表每一个并集；我们需要求得在矩阵中有多少个并集。
上文提到，QU（quick-union）算法中，将元素之间的连接关系用一个数组来保存，数组的值表示元素的父节点的id。

我们来跟着官解一起来构造一个Union-Find类：

```
class UnionFind {
    // 这里的count就是我们要求的岛屿数量，也是并集的数量
    int count; // # of connected components
    // 用来存储元素及连接关系的数组
    int[] parent;
    // 权重表，存储数组中每一个元素的权重，即该节点的子节点数量
    int[] rank;

    // 构造函数
    public UnionFind(char[][] grid) { // for problem 200
        count = 0;
        int m = grid.length;
        int n = grid[0].length;
        // 将二维数组转化成一位数组，并初始化parent和rank数组
        parent = new int[m * n];
        rank = new int[m * n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
            // 如果该节点值为1，代表该节点是根节点，将id的值存入，并count++
            if (grid[i][j] == '1') {
                parent[i * n + j] = i * n + j;
                ++count;
            }
            // 初始化每一个节点的权重为0
            rank[i * n + j] = 0;
            }
        }
    }

    // 查找一个元素的根节点位置,这里使用到路径压缩
    // i 为当前节点， parent[i] 为父节点
    public int find(int i) { // path compression
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }

    public void union(int x, int y) { // union with rank
    // 找到两个节点的根节点
    int rootx = find(x);
    int rooty = find(y);
    // 如果根节点不同，则代表x和y没有连接
    if (rootx != rooty) {
        // 将x和y所在的两棵树进行合并，小树放到大树下面
        if (rank[rootx] > rank[rooty]) {
        parent[rooty] = rootx;
        } else if (rank[rootx] < rank[rooty]) {
        parent[rootx] = rooty;
        } else {
        parent[rooty] = rootx; rank[rootx] += 1;
        }
        // x和y并不是独立的岛，需要合并，count--
        --count;
    }
    }

    public int getCount() {
        return count;
    }
}

//使用我们刚才构造的Union-Find类：
public int numIslands(char[][] grid) {
    // 非空判断
    if (grid == null || grid.length == 0) {
    return 0;
    }

    // 初始化UF类
    int nr = grid.length;
    int nc = grid[0].length;
    int num_islands = 0;
    UnionFind uf = new UnionFind(grid);

    // 
    for (int r = 0; r < nr; ++r) {
        for (int c = 0; c < nc; ++c) {
            // 如果是岛，则向四个方向探索，并做范围判断；同时连接两个岛
            if (grid[r][c] == '1') {
                grid[r][c] = '0';
                if (r - 1 >= 0 && grid[r-1][c] == '1') {
                    uf.union(r * nc + c, (r-1) * nc + c);
                }
                if (r + 1 < nr && grid[r+1][c] == '1') {
                    uf.union(r * nc + c, (r+1) * nc + c);
                }
                if (c - 1 >= 0 && grid[r][c-1] == '1') {
                    uf.union(r * nc + c, r * nc + c - 1);
                }
                if (c + 1 < nc && grid[r][c+1] == '1') {
                    uf.union(r * nc + c, r * nc + c + 1);
                }
            }
        }
    }

    return uf.getCount();
}
```


