一 递归  超时

    class Solution {
        int m;
        int n;
        public int minPathSum(int[][] grid) {
            m = grid.length;
            n = grid[0].length;
            return helper(grid, 0, 0);
        }
        private int helper(int[][] grid, int row, int column) {
            if (row == m - 1 && column == n - 1) {
                return grid[row][column];
            }

            if (row == m - 1) {
                return grid[row][column] + helper(grid, row, column + 1);
            }

            if (column == n - 1) {
                return grid[row][column] + helper(grid, row + 1, column);
            }

            int down = helper(grid, row + 1, column);
            int right = helper(grid, row, column + 1);
            return grid[row][column] + Math.min(down, right);
        }
    }

二 自顶向下 记忆化搜索 通过

    class Solution {
        int m;
        int n;
        Integer[][] memo;

        public int minPathSum(int[][] grid) {
            m = grid.length;
            n = grid[0].length;
            memo = new Integer[m][n];
            return helper(grid, 0, 0);

        }

        private int helper(int[][] grid, int row, int column) {
            if (row == m - 1 && column == n - 1) {
                return grid[row][column];
            }

            if (memo[row][column] == null) {
                if (row == m - 1) {
                    memo[row][column] = grid[row][column] + helper(grid, row, column + 1);
                } else if (column == n - 1) {
                    memo[row][column] = grid[row][column] + helper(grid, row + 1, column);
                } else {
                    int down = helper(grid, row + 1, column);
                    int right = helper(grid, row, column + 1);
                    memo[row][column] = grid[row][column] + Math.min(down, right);
                }
            }
            return memo[row][column];
        }
    }

三 动态规划 自底向上

    class Solution {
        public int minPathSum(int[][] grid) {
            int m = grid.length;
            int n = grid[0].length;
            int[][] memo = new int[m][n];
            for (int row = m - 1; row >= 0; row--) {
                for (int column = n - 1; column >= 0; column--) {
                    if (row == m - 1 && column == n - 1) {
                        memo[row][column] = grid[row][column];
                    } else if (row == m - 1) {
                        memo[row][column] = grid[row][column] + memo[row][column + 1];
                    } else if (column == n - 1) {
                        memo[row][column] = grid[row][column] + memo[row + 1][column];
                    } else {
                        int down = memo[row + 1][column];
                        int right = memo[row][column + 1];
                        memo[row][column] = grid[row][column] + Math.min(down, right);
                    }
                }
            }
            return memo[0][0];
        }
    }