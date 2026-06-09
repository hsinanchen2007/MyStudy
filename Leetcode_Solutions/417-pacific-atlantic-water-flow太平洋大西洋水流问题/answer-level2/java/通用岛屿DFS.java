```
class Solution {
    private int[][] dirArr = new int[][]{{1,0},{0,1},{-1,0},{0,-1}};

    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        List<List<Integer>> ansList = new ArrayList<>();
        if (matrix == null || matrix.length < 1 || matrix[0].length < 1) {
            return ansList;
        }
        int row = matrix.length, col = matrix[0].length;
        boolean[][] pVisited = new boolean[row][col], aVisited = new boolean[row][col];
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (r == 0 || c == 0) {
                    dfs(matrix, pVisited, r, c, matrix[r][c]);
                }
                if (r == row - 1 || c == col - 1) {
                    dfs(matrix, aVisited, r, c, matrix[r][c]);
                }

            }
        }
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (pVisited[r][c] && aVisited[r][c]) {
                    ansList.add(Arrays.asList(r, c));
                }
            }
        }
        return ansList;
    }

    private void dfs(int[][] matrix, boolean[][] visited, int r, int c, int height) {
        if (inArea(matrix, r, c) && !visited[r][c] && matrix[r][c] >= height) {
            visited[r][c] = true;
            for (int[] dir : dirArr) {
                dfs(matrix, visited, r + dir[0], c + dir[1], matrix[r][c]);
            }
        }

    }

    private boolean inArea(int[][] matrix, int r, int c) {
        return r >=0 && r < matrix.length && c >=0 && c < matrix[0].length;
    }
}
```
