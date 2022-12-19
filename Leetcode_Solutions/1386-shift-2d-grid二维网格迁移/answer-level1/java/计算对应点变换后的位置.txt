```
class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int n = grid.length;
        int m = grid[0].length;

        int[][] temp = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 计算该点在变换后所在的位置
                int l = (i * m + j + k) % (n * m);
                temp[l / m][l % m] = grid[i][j];
            }
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Integer> sub = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                sub.add(temp[i][j]);
            }
            result.add(sub);
        }

        return result;
    }
}
```
