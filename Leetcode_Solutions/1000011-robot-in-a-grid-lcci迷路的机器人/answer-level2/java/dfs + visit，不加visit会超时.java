```
class Solution {
    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid == null || obstacleGrid.length == 0) {
            return null;
        }
        List<List<Integer>> res = new ArrayList<>();
        int row = obstacleGrid.length;
        int column = obstacleGrid[0].length;
        boolean[][] visit = new boolean[row][column];
        dfs(obstacleGrid, 0, 0, res, row, column, visit);
        return res;
    }

    private boolean dfs(int[][] obstacleGrid, int x, int y, List<List<Integer>> res, int row, int column, boolean[][] visit) {
        if (x < 0 || x >= row || y < 0 || y >= column || obstacleGrid[x][y] == 1 || visit[x][y]) {
            return false;
        }
        visit[x][y] = true;
        ArrayList<Integer> list = new ArrayList<>();
        list.add(x);
        list.add(y);
        res.add(list);
        if (x == row - 1 && y == column - 1) {
            return true;
        }

        if (dfs(obstacleGrid, x + 1, y, res, row, column, visit) || (dfs(obstacleGrid, x, y + 1, res, row, column, visit))) {
            return true;
        }
        res.remove(res.size() - 1);
        return false;
    }
}
```
