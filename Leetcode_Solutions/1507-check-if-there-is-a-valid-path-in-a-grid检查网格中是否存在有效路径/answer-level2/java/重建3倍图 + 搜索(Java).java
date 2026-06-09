# 思路

这道题一个比较直观的思路是将每个方格看成 `3 * 3`的小方格，然后分别对`1 - 6`进行染色，然后转化为简单的搜索即可，BFS、DFS均可。

# 代码
```java
class Solution {
    
    private int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    public boolean hasValidPath(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] newGrid = new int[n * 3][m * 3];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                color(newGrid, i * 3, j * 3, grid[i][j]);
            }
        }
        boolean[][] seen = new boolean[n * 3][m * 3];
        Deque<int[]> queue = new ArrayDeque<>();
        for(int i = 0; i < 3; i++){
            for(int j = 0 ; j < 3; j++){
                if(newGrid[i][j] == 1){
                    queue.add(new int[]{i, j});
                    seen[i][j] = true;
                }
            }
        }
        while(!queue.isEmpty()){
            int[] cur = queue.poll();
            if(cur[0] / 3 == n - 1 && cur[1] / 3 == m - 1){
                return true;
            }
            for(int[] dir: dirs){
                int nr = cur[0] + dir[0];
                int nc = cur[1] + dir[1];
                if(nr < 0 || nc < 0 || nr >= n * 3 || nc >= m * 3 || newGrid[nr][nc] == 0 || seen[nr][nc]){
                    continue;
                }
                seen[nr][nc] = true;
                queue.add(new int[]{nr, nc});
            }
        }
        return false;
    }
    
    private void color(int[][] newGrid, int r, int c, int label){
        if(label == 1){
            newGrid[r + 1][c] = 1;
            newGrid[r + 1][c + 1] = 1;
            newGrid[r + 1][c + 2] = 1;
        } else if(label == 2){
            newGrid[r][c + 1] = 1;
            newGrid[r + 1][c + 1] = 1;
            newGrid[r + 2][c + 1] = 1;
        } else if(label == 3){
            newGrid[r + 1][c] = 1;
            newGrid[r + 1][c + 1] = 1;
            newGrid[r + 2][c + 1] = 1;
        } else if(label == 4){
            newGrid[r + 1][c + 1] = 1;
            newGrid[r + 1][c + 2] = 1;
            newGrid[r + 2][c + 1] = 1;
        } else if(label == 5){
            newGrid[r + 1][c] = 1;
            newGrid[r + 1][c + 1] = 1;
            newGrid[r][c + 1] = 1;
        } else {
            newGrid[r][c + 1] = 1;
            newGrid[r + 1][c + 1] = 1;
            newGrid[r + 1][c + 2] = 1;
        }
    }
}
```