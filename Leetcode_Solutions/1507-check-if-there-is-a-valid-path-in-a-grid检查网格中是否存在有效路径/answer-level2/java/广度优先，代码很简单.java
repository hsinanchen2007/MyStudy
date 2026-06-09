```
private int[][][] directions = new int[][][] {
        {},
        {
            {0, 1}, {0, -1}
        },
        {
            {1, 0}, {-1, 0}
        },
        {
            {0, -1}, {1, 0}
        },
        {
            {1, 0}, {0, 1}
        },
        {
            {0, -1}, {-1, 0}
        },
        {
            {-1, 0}, {0, 1}
        }
    };
    
    private boolean check(int[][] grid, int x, int y, int nx, int ny) {
        for(int[] d : directions[grid[nx][ny]]) {
            int i = nx + d[0];
            int j = ny + d[1];
            
            if (x == i && y == j) {
                return true;
            }
        }
        return false;
    }
    
    public boolean hasValidPath(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        if (m == 1 && n == 1) {
            return true;
        }
        
        Queue<Integer> queue = new LinkedList();
        queue.offer(0);
        boolean[][] matrix = new boolean[m][n];
        matrix[0][0] = true;
        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int i = 0; i < size; i++) {
                int num = queue.poll();
                int x = num / 10000;
                int y = num % 10000;
                //System.out.println("x = " + x + " , y = " + y);
                
                for(int[] d : directions[grid[x][y]]) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        continue;
                    }
                    
                    if (matrix[nx][ny]) {
                        continue;
                    }
                    
                    if (!check(grid, x, y, nx, ny)) {
                        continue;
                    }
                    
                    matrix[nx][ny] = true;
                    
                    if (nx == m - 1 && ny == n - 1) {
                        return true;
                    }
                    queue.offer(10000 * nx + ny);
                }
            }
        }
        
        return false;
    }
```
