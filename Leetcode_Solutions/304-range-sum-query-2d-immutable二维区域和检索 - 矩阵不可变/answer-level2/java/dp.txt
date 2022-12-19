奇怪，时间复杂度 怎么这么高 。。。
```
   static class NumMatrix {
        int[][] dp;
        public NumMatrix(int[][] matrix) {
            if (matrix != null && matrix.length != 0) {
                int x = matrix.length;
                int y = matrix[0].length;
                dp = new int[x + 1][y + 1];
                for (int i = 0; i < x; i++) {
                    int sum = 0;
                    for (int j = 0; j < y; j++) {
                        sum += matrix[i][j];
                        dp[i+1][j+1] = i > 0?dp[i][j+1] + sum:sum;
                    }
                }
            }
        }
        public int sumRegion(int row1, int col1, int row2, int col2) {
                return dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1 ] + dp[row1 ][col1];
        }

        public static void main(String[] args) {
            int[][] matrix = new int[][]{
                    {3, 0, 1, 4, 2},
                    {5, 6, 3, 2, 1},
                    {1, 2, 0, 1, 5},
                    {4, 1, 0, 1, 7},
                    {1, 0, 3, 0, 5}
            };
            NumMatrix numMatrix = new NumMatrix(matrix);
            System.out.println(numMatrix.sumRegion(2, 1, 4, 3));
        }
    }
```