### 解题思路
BFS，DFS，并查集。

### 代码
BFS版本：
```java
class NodeIndex {
    int x, y;

    public NodeIndex(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }

        int n = grid.length, m = grid[0].length;
        int nums = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    bfs(grid, i, j);
                    nums++;
                }
            }
        }

        return nums;
    }

    public void bfs(char[][] grid, int i, int j) {
        int n = grid.length, m = grid[0].length;
        int[] dx = new int[]{1, 0, -1, 0};
        int[] dy = new int[]{0, 1, 0, -1};
        Queue<NodeIndex> queue = new LinkedList<>();
        queue.add(new NodeIndex(i, j));
        while (!queue.isEmpty()) {
            NodeIndex node = queue.poll();
            for (int k = 0; k < 4; k++) {
                int nextX = node.x + dx[k];
                int nextY = node.y + dy[k];
                if (isVaild(nextX, nextY, n, m)) {
                    if (grid[nextX][nextY] == '1') {
                        grid[nextX][nextY] = '0';
                        queue.add(new NodeIndex(nextX, nextY));
                    }
                }
            }
        }
    }

    private boolean isVaild(int nextX, int nextY, int n, int m) {
        return nextX >= 0 && nextX < n && nextY >= 0 && nextY < m;
    }
}
```

DFS版本：
```java
class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }

        int n = grid.length, m = grid[0].length;
        int nums = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    // bfs(grid, i, j);
                    dfs(grid, i, j);
                    nums++;
                }
            }
        }

        return nums;
    }
    
    private void dfs(char[][] grid, int i, int j) {
        int n = grid.length, m = grid[0].length;
        int[] dx = new int[]{1, 0, -1, 0};
        int[] dy = new int[]{0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nextX = i + dx[k];
            int nextY = j + dy[k];

            if (isVaild(nextX, nextY, n, m)) {
                if(grid[nextX][nextY] == '1') {
                    grid[nextX][nextY] = '0';
                    dfs(grid, nextX, nextY);
                }
            }
        }
    }

    private boolean isVaild(int nextX, int nextY, int n, int m) {
        return nextX >= 0 && nextX < n && nextY >= 0 && nextY < m;
    }
}
```


并查集版本：
```java
class UF{

    private int[] parent;

    public UF(int n){

        parent = new int[n];
        for(int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }

    public int find(int p){
        if( p != parent[p] )
            parent[p] = find( parent[p] );
        return parent[p];
    }

    public boolean isConnected(int p , int q){
        return find(p) == find(q);
    }

    public void unionElements(int p, int q){

        int pRoot = find(p);
        int qRoot = find(q);

        if( pRoot == qRoot )
            return;

        parent[pRoot] = qRoot;
    }
}

class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }

        int n = grid.length, m = grid[0].length;
        UF uf = new UF(n * m);
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    if (i > 0 && grid[i - 1][j] == '1') {
                        uf.unionElements(i * m + j, (i - 1) * m + j);
                    }
                    if (i <  n - 1 && grid[i + 1][j] == '1') {
                        uf.unionElements(i * m + j, (i + 1) * m + j);
                    }
                    if (j > 0 && grid[i][j - 1] == '1') {
                        uf.unionElements(i * m + j, i * m + j - 1);
                    }
                    if (j < m - 1 && grid[i][j + 1] == '1') {
                        uf.unionElements(i * m + j, i * m + j + 1);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    set.add(uf.find(i * m + j));
                }
            }
        }

        return set.size();
    }
}
```
