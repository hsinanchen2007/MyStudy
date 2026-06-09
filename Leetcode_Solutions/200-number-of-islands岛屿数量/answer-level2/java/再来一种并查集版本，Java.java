### 解题思路
写并查集完全不用想，一门心思瞎写。

### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {
        if(grid == null || grid.length == 0 || grid[0] == null ||grid[0].length == 0) {
            return 0;
        }

        int m = grid.length;
        int n = grid[0].length;

        int len = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    len++;
                }
            }
        }

        UnionFind uf = new UnionFind(m * n, len);

        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, -1, 0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == '0') {
                    continue;
                }

                for (int k = 0; k < 4; k++) {
                    int nextx = i + dx[k];
                    int nexty = j + dy[k];

                    if(!isValid(grid, nextx, nexty) || grid[nextx][nexty] == '0') {
                        continue;
                    }

                    uf.connect(i * n + j, nextx * n + nexty);
                }
            }
        }

        return uf.query();
    }
    
    private boolean isValid(char[][] grid, int i, int j) {
        int m = grid.length;
        int n = grid[0].length;

        return i >= 0 && i < m && j >= 0 && j < n;
    }
}


class UnionFind {
    private int[] father;
    private int cnt;

    private int find(int x) {
        if(x == father[x]) {
            return x;
        }

        return father[x] = find(father[x]);
    }

    public UnionFind(int n, int len) {
        father = new int[n + 1];
        cnt = len;
        for (int i = 0; i <= n; i++) {
            father[i] = i;
        }
    }

    public void connect(int a, int b) {
        int fatherA = find(a);
        int fatherB = find(b);

        if(fatherA != fatherB) {
            father[fatherA] = fatherB;
            cnt--;
        }
    }

    public int query() {
        return cnt;
    }
}
```