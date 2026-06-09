# 连通块问题的大总结请参考我的博客https://blog.csdn.net/qq_21515253/article/details/99703065
# 本人根据leetcode刷题经验做了x分享，欢迎大家指教
### Problem

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
		11110
		11010
		11000
		00000

Output: 1



这个问题和第一个问题应该非常类似，都是二维矩阵区域内的图问题。

**通过Problem One（见博客）我们已经了解了此类问题的搜索方法和并查集的uniton方法，即可在无需特地构边的情况下，直接遍历Node的上、下、左、右方向完成搜索和uniton，对于这种结构特殊的图问题，我们可以总结其边的规律，以达到更好得构造算法的目的，不必一未得想去构造标准的邻接矩阵，使简单的问题复杂化。**

对于本题的点构造与边构造与Problem One（见我的博客）如出一辙，这里不再赘述。

笔者直接开始策略分析。

### 策略

岛屿的数量很容易发现就是’1’的点构成的**连通块的数量**。

对于连通块数量的计算，我们很容易想到采用并查集，简单直接。

#### 策略一：并查集

判断‘1‘的node有多少个top点，即找并查集树林中有几棵树，即为岛屿数量。

首先我们在Problem One的并查集基础上增加寻找树的数量的method。

```java
class UnionFind {
    HashMap<Integer, Integer> parent = new HashMap<>();
    HashMap<Integer, Integer> size = new HashMap<>();
    HashSet<Integer> top = new HashSet<>();   //新增top的node的搜索
    
    public UnionFind() {}
    
    public UnionFind(char[][] grid, int row, int col) {   //新增top初始化
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    top.add((i * col + j));
                }
            }
        }
    }
    
    /*
     *	对于被合并的node，从top中移除
     */
    public void union(int node1, int node2) {
        if (!parent.containsKey(node1)) {
            parent.put(node1, node1);
            size.put(node1, 1);
        }
        
        if (!parent.containsKey(node2)) {
            parent.put(node2, node2);
            size.put(node2, 1);
        }
        
        int root1 = find(node1);
        int root2 = find(node2);
        if (root1 == root2) {
            return;
        }
        if (size.get(root1) < size.get(root2)) {
            size.put(root2, size.get(root1) + size.get(root2));
            parent.put(root1, root2);
            top.remove(root1);
        } else {
            size.put(root1, size.get(root1) + size.get(root2));
            parent.put(root2, root1);
            top.remove(root2);
        }
    }
    
    public int find(int node) {
        if (!parent.containsKey(node)) {
            parent.put(node, node);
        }
        while (!(node == (parent.get(node)))) {
            node = parent.get(node);
        }
        return node;
    }
    
    public boolean connected(int node1, int node2) {
        return find(node1) == find(node2);
    }
    
    public int getTop() {
        return top.size();
    }
}
```

接下来，我们就可以非常简单的应用Uniton-Find，进行添加即可。

```java
class Solution {
    private char[][] grid;
    private int row;
    private int col;
    
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        
        int row = grid.length;
        int col = grid[0].length;
        UnionFind uf = new UnionFind(grid, col, row);
        
        //union
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    if (j + 1 < col && grid[i][j + 1] == '1') {
                        uf.union(i * col + j, i * col + j + 1);
                    }
                    
                    if (i + 1 < row && grid[i + 1][j] == '1') {
                        uf.union((i + 1) * col + j, i * col + j);
                    }
                    
                }
            }
        }
        
        return uf.getTop();
    }
}
```

当然，我们怎么可能能忘记DFS的教导呢

#### 策略二：DFS

在这里，介绍一个小技巧

回想Problem One中，**搜索过程中我们对部分’O‘进行标记，这种对dfs过的路径进行标记，以保证下次不被访问的方法可以称为“格式化”。**

**本题，我们可以通过把从某点出发DFS经过的区域标记为'0',保证下回不再搜索此点，即“格式化”经过的区域。**

每次对一个点进行搜索，连通块个数加1，然后对与此点连通的所有点格式化，下次从未格式化的点再开始搜索，个数加1....

```java
class Solution {
    private char[][] grid;
    private int row;
    private int col;
   
    public int numIslands(char[][] grid) {
        int count = 0;
        this.grid = grid;
        if (grid == null || grid.length == 0) {
            return count;
        }
        this.row = grid.length;
        this.col = grid[0].length;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j);
                }
            }
        }
        return count;
    }
    
    public void dfs(int i, int j) {
        if (i >= row || i < 0 || j >= col || j < 0 || grid[i][j] != '1') {
            return;
        }
        //！！！！！！！！！！！！！！格式化
        grid[i][j] = '0';
        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }
}
```

最后，希望大家通过这个问题加深对DFS和并查集对处理连通块问题的能力。

