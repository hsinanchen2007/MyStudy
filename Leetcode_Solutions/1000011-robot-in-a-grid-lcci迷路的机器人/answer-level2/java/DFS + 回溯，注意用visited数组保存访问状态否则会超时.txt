```
class Solution {
    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        List<List<Integer>> ans = new ArrayList<>();
        if (obstacleGrid.length == 0 || obstacleGrid[0].length == 0) return ans;
        int r = obstacleGrid.length, c = obstacleGrid[0].length;
        boolean[][] vis = new boolean[r][c];
        dfs(obstacleGrid, 0, 0, ans, vis);
        return ans;
    }

    boolean dfs(int[][] obstacleGrid, int x, int y, List<List<Integer>> ans, boolean[][] vis) {
        int r = obstacleGrid.length, c = obstacleGrid[0].length;
        if (x >= r || y >= c || obstacleGrid[x][y] == 1 || vis[x][y]) return false;
        if (x == r-1 && y == c-1) {
            ans.add(Arrays.asList(new Integer[] {x, y}));
            return true;
        }
        ans.add(Arrays.asList(new Integer[] {x, y}));
        vis[x][y] = true;
        if (dfs(obstacleGrid, x+1, y, ans, vis)) return true;
        if (dfs(obstacleGrid,  x, y+1, ans, vis)) return true;
        ans.remove(ans.size()-1);
        return false;
    }
}
```