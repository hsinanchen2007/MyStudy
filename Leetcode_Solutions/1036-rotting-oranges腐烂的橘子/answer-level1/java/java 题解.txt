### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {

        Queue<int[]> q = new LinkedList<>();
        int row = grid.length;
        int col = grid[0].length;
        int[] arr = {0, 1, 0, -1, 0};
        int minute = 0;
        int count = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.offer(new int[]{i, j});
                }
                if (grid[i][j] == 1) {
                    count += 1;
                }
            }
        }

        while (!q.isEmpty()) {
            if (count == 0) {
                return minute;
            }
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int[] xy = q.poll();
                for (int k = 0; k < 4; k++) {
                    int nx = xy[0] + arr[k];
                    int ny = xy[1] + arr[k + 1];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
                        count -= 1;
                        q.offer(new int[]{nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            minute += 1;
        }
        if (count == 0) {
            return minute;
        }
        return -1;
    }
}
```