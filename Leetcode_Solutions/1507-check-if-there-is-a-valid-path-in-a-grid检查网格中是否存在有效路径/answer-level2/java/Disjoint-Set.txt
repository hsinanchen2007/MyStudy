### 检查图的连通性问题，可以使用并查集来做，但是为什么，cpp同样的代码，就TLE，而java就可以通过

看了一圈题解都是用dfs、bfs来做的，我尝试使用并查集做了一下。

**说一下思路，首先遍历整个grid，对于其中的每一个值，可以连接哪个street，对于可以连接的street进行合并，最后通过查找祖先节点的方式检查两个节点在不在一个集合中**
```java
class Solution {
    int N = 90000 + 1;
    int[] nums = new int[N];
    void init(int n) {
        for (int i = 0; i < n; i++) {
            nums[i] = i;
        }
    }
    int find(int x) {
        if (x == nums[x]) return x;
        return nums[x] = find(nums[x]);
    }
    void merge(int x,int y) {
        nums[find(x)] = nums[find(y)];
    }
    public boolean hasValidPath(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        init(m*n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (j - 1 >= 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6)) {
                        merge(i*m + j - 1,i*m + j);
                    }
                    if (j + 1 < m && (grid[i][j + 1]  == 1|| grid[i][j + 1] == 3 || grid[i][j + 1] == 5)) {
                        merge(i*m + j,i*m + j + 1);
                    }
                }else if (grid[i][j] == 2) {
                    if (i - 1 >= 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 4 || grid[i - 1][j] == 3)) {
                        merge((i - 1)*m + j,i*m + j);
                    }
                    if (i + 1 < n && (grid[i + 1][j] == 2||grid[i + 1][j] == 5||grid[i + 1][j] == 6)) {
                        merge(i*m + j,(i + 1)*m + j);
                    }

                }else if (grid[i][j] == 3) {
                    if (j - 1 >= 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6)) {
                        merge(i*n + j - 1,i*n + j);
                    }
                    if (i + 1 < n && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6)) {
                        merge(i*m + j,(i + 1)*m + j);
                    }
                }else if (grid[i][j] == 4) {
                    if (j + 1 < m && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5)) {
                        merge(i * m + j,i*m + j + 1);
                    }
                    if (i + 1 < n && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6)) {
                        merge(i*m + j,(i + 1)*m + j);
                    }
                }else if (grid[i][j] == 5) {
                    if (j - 1 >= 0 && (grid[i][j - 1] == 1|| grid[i][j - 1] == 4 || grid[i][j - 1] == 6)) {
                        merge(i*m + j - 1,i * m + j);
                    }
                    if (i - 1 >= 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4)) {
                        merge((i - 1)*m + j,i*m + j);
                    }
                }else if (grid[i][j] == 6) {
                    if (j + 1 < m && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5)) {
                        merge(i *m + j,i*m + j + 1);
                    }
                    if (i - 1 >= 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4)) {
                        merge((i - 1)*m + j,i * m + j);
                    }
                }
            }
        }
        return find(0) == find(m*n - 1);
    }
}
```