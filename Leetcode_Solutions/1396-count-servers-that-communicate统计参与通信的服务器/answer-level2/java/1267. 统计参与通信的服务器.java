### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countServers(int[][] grid) {
        int[] rows = new int[grid.length];
        int[] columns = new int[grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            int sum = 0;
            for (int j = 0; j < grid[0].length; j++) {
                sum += grid[i][j];
            }
            rows[i] = sum;
        }

        for (int i = 0; i < grid[0].length; i++) {
            int sum = 0;
            for (int[] row : grid) {
                sum += row[i];
            }
            columns[i] = sum;
        }
        int result = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1 && (rows[i] + columns[j]) > 2) {
                    result++;
                }
            }
        }
        return result;
    }
}
```