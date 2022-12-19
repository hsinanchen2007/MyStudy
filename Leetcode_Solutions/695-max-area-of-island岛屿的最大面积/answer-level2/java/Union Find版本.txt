### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if(grid == null || grid.length == 0 || grid[0] == null ||grid[0].length == 0) {
            return 0;
        }

        int m = grid.length;
        int n = grid[0].length;

        int len = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    len++;
                }
            }
        }

        UnionFind uf = new UnionFind(m * n, len);

        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, -1, 0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }

                for (int k = 0; k < 4; k++) {
                    int nextx = i + dx[k];
                    int nexty = j + dy[k];

                    if(!isValid(grid, nextx, nexty) || grid[nextx][nexty] == 0) {
                        continue;
                    }

                    uf.connect(i * n + j, nextx * n + nexty);
                }
            }
        }

        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                max = Math.max(uf.query(i * n + j), max);
            }
        }
        return max;
    }

    private boolean isValid(int[][] grid, int i, int j) {
        int m = grid.length;
        int n = grid[0].length;

        return i >= 0 && i < m && j >= 0 && j < n;
    }
}

class UnionFind {
    private int[] father;
    private int[] size;

    private int find(int x) {
        if(x == father[x]) {
            return x;
        }

        return father[x] = find(father[x]);
    }

    public UnionFind(int n, int len) {
        father = new int[n + 1];
        size = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            father[i] = i;
            size[i] = len > 0 ? 1 : 0;
        }
    }

    public void connect(int a, int b) {
        int fatherA = find(a);
        int fatherB = find(b);

        if(fatherA != fatherB) {
            father[fatherA] = fatherB;
            size[fatherB] += size[fatherA];
        }
    }

    public int query(int a) {
        int fatherA = find(a);
        return size[fatherA];
    }
}
```