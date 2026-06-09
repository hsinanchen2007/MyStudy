```
class Solution {
    private LinkedList<List<Integer>> res = new LinkedList<>();
    private int rows;
    private int cols;
    private boolean complete = false;

    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        rows = obstacleGrid.length;
        if (rows < 1) return res;

        cols = obstacleGrid[0].length;
        if (cols < 1) return res;

        // 提前预知终点是否可达
        if (obstacleGrid[rows - 1][cols - 1] == 1) return res;

        helper(obstacleGrid, 0, 0);
        // 若未找到可达路径则返回空
        return complete ? res : new LinkedList<>();
    }

    private void helper(int[][] obstacleGrid, int row, int col) {
        // 超界或不可达
        if (row >= rows || col >= cols || obstacleGrid[row][col] == 1) {
            return;
        }
        
        // 到达终点
        if (row == rows - 1 && col == cols - 1) {
            res.add(Arrays.asList(row, col));
            complete = true;
            return;
        }

        // 处理当前位置
        res.add(Arrays.asList(row, col));

        // 向右走
        helper(obstacleGrid, row, col + 1);
        if (complete) {
            return;
        }

        // 向下走
        helper(obstacleGrid, row + 1, col);
        if (complete) {
            return;
        }
        // 回溯，对于当前节点，如果向右或向下都不能 complete，
        // 则说明当前节点是不可到达终点的，因此 remove
        res.removeLast();
    }
}
```
