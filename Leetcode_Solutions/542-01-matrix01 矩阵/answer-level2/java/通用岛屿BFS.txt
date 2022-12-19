```
class Solution {
    private int[][] dirArr = new int[][]{{1,0},{0,1},{-1,0},{0,-1}};

    public int[][] updateMatrix(int[][] matrix) {
        int row = matrix.length, col = matrix[0].length;
        Queue<int[]> queue = new LinkedList<>();
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (matrix[r][c] == 0) {
                    queue.add(new int[]{r, c});
                } else {
                    matrix[r][c] = Integer.MAX_VALUE;
                }
            }
        }
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] pArr = queue.poll();
                int r = pArr[0], c = pArr[1];
                for (int[] dir : dirArr) {
                    int nR = r + dir[0], nC = c + dir[1];
                    if (inArea(matrix, nR, nC) && matrix[nR][nC] == Integer.MAX_VALUE) {
                        matrix[nR][nC] = matrix[r][c] + 1;
                        queue.offer(new int[]{nR, nC});
                    }
                }
            }
        }
        return matrix;
    }

    private boolean inArea(int[][] matrix, int r, int c) {
        return r >= 0 && r < matrix.length && c >= 0 && c < matrix[0].length;
    }
}
```
