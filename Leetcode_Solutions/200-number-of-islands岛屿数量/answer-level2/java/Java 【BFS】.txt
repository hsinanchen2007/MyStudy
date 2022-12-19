### 解题思路
和994烂橘子、286墙与门一个广度遍历法，遍历完标记，全标记完就得到岛屿数了。

### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0)
            return 0;
        
        int M = grid.length;
        int N = grid[0].length;

        int count = 0;

        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if (grid[i][j] == '1') {
                    count++;
                    grid[i][j] = '2';
                    bfs (grid, M, N, i, j);
                }
            }
        }
        return count;
    }

    public void bfs(char[][] grid, int Row, int Col, int i, int j) {
        int M = Row;
        int N = Col;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{i,j});
        while (!queue.isEmpty()) {
            int[] land = queue.poll();
            int r = land[0];
            int c = land[1];

            if (r > 0 && grid[r - 1][c] == '1'){
                grid[r - 1][c] = '2';
                queue.add(new int[]{r - 1,c});
            }

            if (c > 0 && grid[r][c - 1] == '1'){
                grid[r][c - 1] = '2';
                queue.add(new int[]{r,c - 1});
            }

            if (r + 1 < M && grid[r + 1][c] == '1'){
                grid[r + 1][c] = '2';
                queue.add(new int[]{r + 1,c});
            }

            if (c + 1 < N && grid[r][c + 1] == '1'){
                grid[r][c + 1] = '2';
                queue.add(new int[]{r,c + 1});
            }
        }
    }
}
```