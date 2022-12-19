# 1.深度优先搜索
```
class Solution {
    private char[][] grid;
    private int count = 0;
    private int M;
    private int N;
    
    public int numIslands(char[][] grid) {
        M = grid.length;
        if(M == 0) return 0;
        N = grid[0].length;
        this.grid = grid;
        
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i, j);
                }
            }
        }
        return count;
    }
    
    private void dfs(int i, int j) {
        if(grid[i][j] == '0') return;
        else grid[i][j] = '0';
        if(i != M - 1) dfs(i + 1, j);
        if(i != 0) dfs(i - 1, j);
        if(j != N - 1) dfs(i, j + 1);
        if(j != 0) dfs(i, j - 1);

    }
}
```
# 广度优先搜索
```
class Solution {
    public int numIslands(char[][] grid) {
        int M = grid.length;
        if(M == 0) return 0;
        int N = grid[0].length;
        int count = 0;
        
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(0);
        
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    queue.add(i * N + j);
                    while(!queue.isEmpty()) {
                        int x = queue.poll();
                        int m = x / N, n = x % N;
                        if(grid[m][n] == '0') continue;
                        else grid[m][n] = '0';
                        if(m != 0) queue.add(x - N);
                        if(m != M - 1) queue.add(x + N);
                        if(n != 0) queue.add(x - 1);
                        if(n != N - 1) queue.add(x + 1);
                    }
                }
            }
        }
        return count;
    }
}
```


