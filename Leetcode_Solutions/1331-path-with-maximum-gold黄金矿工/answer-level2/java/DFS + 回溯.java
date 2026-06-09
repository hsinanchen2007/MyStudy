### 解题思路
遍历二维数组的每个节点，当节点为0不进行任何操作，然后对有值节点进行DFS+回溯，注意结束条件即可

### 代码

```java
class Solution {
    public int getMaximumGold(int[][] grid) {
      if(grid == null || grid.length == 0){
            return 0;
        }
        boolean[][] isVisit = new boolean[grid.length][grid[0].length];
        //遍历每一个点作为起始点，0除外
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] != 0){
                    generateGold(i, j, grid, isVisit);
                }
            }
        }
        return maxGold;
    }
    private int max = 0;
    private int maxGold = 0;
    private void generateGold(int i, int j, int[][] grid, boolean[][] isVisit) {
        //判断不成立的条件
        if(i < 0 || i > grid.length - 1 || j < 0 || j > grid[0].length - 1 || grid[i][j] == 0 || isVisit[i][j]){
            return;
        }
        //设置该路径已经访问过
        isVisit[i][j] = true;
        //计算结果
        max = Math.max(max, max + grid[i][j]);
        //进行DFS,上，右，下，左
        generateGold(i - 1, j, grid, isVisit);
        generateGold(i, j + 1, grid, isVisit);
        generateGold(i + 1, j, grid, isVisit);
        generateGold(i, j - 1, grid, isVisit);
        isVisit[i][j] = false;
        maxGold = Math.max(max, maxGold);
        max -= grid[i][j];
    }
}
```