```java
class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        if (k == 0) {
            return transfor(grid);
        }
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] arr = new int[rows][cols];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int[] index = calculateIndex(i, j, grid, k);
                arr[index[0]][index[1]] = grid[i][j];
            }
        }
        return transfor(arr);
    }
    private int[] calculateIndex(int i, int j, int[][] grid, int k) {
        int[] res = new int[2];
        for (int a = 0; a < k; a++) {
            if (++j >= grid[0].length) {
                j = 0;
                i++;
            }
            if (i >= grid.length) {
                i = 0;
            }
        }
        res[0] = i;
        res[1] = j;
        return res;
    }
    private List<List<Integer>> transfor(int[][] grid) {
        List<List<Integer>> res = new ArrayList<>();
        for (int[] row : grid) {
            List<Integer> temp = new ArrayList<>();
            for (int item : row) {
                temp.add(item);
            }
            res.add(temp);
        }
        return res;
    }
}
```