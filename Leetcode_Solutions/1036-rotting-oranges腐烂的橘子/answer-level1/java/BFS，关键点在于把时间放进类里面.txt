### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        if(grid == null || grid.length == 0) {
            return -1;
        }
        
        int minute = 0;
        int m = grid.length, n = grid[0].length;
        
        Queue<Point> queue = new LinkedList<>();
        int cnt = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    queue.add(new Point(i, j, 0));
                } else if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        
        
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, -1, 0, 1};
        while(!queue.isEmpty()) {
            Point poll = queue.poll();
            minute = poll.minute;
            int x = poll.x;
            int y = poll.y;
            
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if(isValid(nx, ny, m, n) && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    cnt--;
                    queue.add(new Point(nx, ny, minute + 1));
                }
            }
        }
        
        return cnt == 0 ? minute : -1;
    }
    
    private boolean isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}

class Point {
    int x;
    int y;
    int minute;
    public Point(int x, int y, int minute) {
        this.x = x;
        this.y = y;
        this.minute = minute;
    }
}
```