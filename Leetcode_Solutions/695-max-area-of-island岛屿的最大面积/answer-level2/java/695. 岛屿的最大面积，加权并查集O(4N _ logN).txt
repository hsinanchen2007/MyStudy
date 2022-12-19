### 解题思路
把每个为1的点和周围为1的点合并到同一个集合（表示同一个岛屿），这个操作需要 $4N$ 的时间复杂度。

合并两个点到同一个集合，使用加权并查集，并查集的权值为岛屿的大小。
并查集的操作最好情况下时间复杂度为1，最坏情况下为$logN$。

这题也可以用搜索解答，懒得再写了
**相关题目** [463. 岛屿的周长，DFS](https://leetcode-cn.com/problems/island-perimeter/solution/463-dao-yu-de-zhou-chang-dfs-by-sybil63-2/)

### 代码
```java
class Solution {
    int[] id; // 并查集的id，id = i表示当前节点为根节点，否则为当前节点的父节点的id
    int[] sz; // 并查集的权值，表示以i为根的子树的大小，用于优化合并操作

    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        int[] dx = new int[]{1, -1, 0, 0};
        int[] dy = new int[]{0, 0, 1, -1};
        int X = grid.length;
        int Y = grid[0].length;

        id = new int[X * Y];
        sz = new int[X * Y];
        // 初始化并查集
        for (int x = 0; x < X; ++x) {
            for (int y = 0; y < Y; ++y) {
                int i = x * Y + y;
                id[i] = i;
                if (grid[x][y] == 1) sz[i] = 1;
            }
        }

        // 合并岛屿
        for (int x = 0; x < X; ++x) {
            for (int y = 0; y < Y; ++y) {
                int p = x * Y + y;
                if (grid[x][y] == 0) continue;
                for (int i = 0; i < 4; ++i) {
                    int adjX = x + dx[i];
                    int adjY = y + dy[i];
                    if (adjX < 0 || adjX >= X || adjY < 0 || adjY >= Y || grid[adjX][adjY] == 0)
                        continue;
                    int q = adjX * Y + adjY;
                    // System.out.println("union: " + p + ", " + q);
                    union(p, q);
                }
            }
        }

        for (int i = 0; i < X*Y; ++i) {
            if (sz[i] > maxArea)  maxArea = sz[i];
        }
        return maxArea;
    }

    private int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]]; //路径压缩，减半树的高度
            i = id[i];
        }
        return i;
    }
    
    private void union(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (i == j) return;
        // 把小的树连接到大的上，避免退化为线性
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        // System.out.println("size: " + i + "|" + sz[i] + ", " + j + "|" + sz[j]);
    }
}
```