### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private int[][] dirs = new int[][]{{0, 1}, {1, 0}};
    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid == null
                || obstacleGrid.length == 0
                || obstacleGrid[0] == null
                || obstacleGrid[0].length == 0
                || obstacleGrid[0][0] == 1
                || obstacleGrid[obstacleGrid.length - 1][obstacleGrid[0].length - 1] == 1) {
            return new ArrayList<>();
        }
        res.add(new ArrayList<>(Arrays.asList(0, 0)));
        return backTrace(obstacleGrid, 0, 0) ? res : new ArrayList<>();
    }

    private boolean backTrace(int[][] obstacleGrid, int row, int col) {
        if (row == obstacleGrid.length - 1 && col == obstacleGrid[0].length - 1) {
            return true;
        }
        for (int i = 0; i < dirs.length; i++) {
            int m = row + dirs[i][0];
            int n = col + dirs[i][1];
            res.add(new ArrayList<>(Arrays.asList(m, n)));
            if (m < obstacleGrid.length && n < obstacleGrid[0].length && obstacleGrid[m][n] == 0 && backTrace(obstacleGrid, m, n)) {
                return true;
            }
            res.remove(res.size() - 1);
        }
        return false;
    }
}
```