### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return -1;
        }
        Queue<int[]> queue = new LinkedList<>();
        int freshCount = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 2) {
                    queue.add(new int[]{i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }

            }
        }
        int res = 0;

        while (freshCount > 0 && !queue.isEmpty()) {
            res++;
            int size = queue.size();
            for (int m = 0; m < size; m++) {
                int[] xy = queue.poll();
                int x = xy[0];
                int y = xy[1];
                if (x > 0 && grid[x - 1][y] == 1) {
                    freshCount--;
                    queue.add(new int[]{x - 1, y});
                    grid[x - 1][y] = 2;
                }
                if (x < grid.length - 1 && grid[x + 1][y] == 1) {
                    freshCount--;
                    queue.add(new int[]{x + 1, y});
                    grid[x + 1][y] = 2;
                }
                if (y > 0 && grid[x][y - 1] == 1) {
                    freshCount--;
                    queue.add(new int[]{x, y - 1});
                    grid[x][y-1] = 2;
                }
                if (y < grid[0].length - 1 && grid[x][y + 1] == 1) {
                    freshCount--;
                    queue.add(new int[]{x, y + 1});
                    grid[x][y+1] = 2;
                }
            }
        }
        return (freshCount == 0) ? res : -1;
    }
}
```