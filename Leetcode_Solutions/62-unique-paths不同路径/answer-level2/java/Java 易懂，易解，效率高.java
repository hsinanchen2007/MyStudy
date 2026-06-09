**1.这是一道动态规划题，同时也是一道数学题;
2.画图就可以找到其中的规律;
3.由已知的`m`和`n`可以求出初始位置`[0][0]`到每个位置的`[m][n]`二维数组任意一个位置的解法种类,同时最后一个位置的值也是答案;
4.完结。**

        public int uniquePaths(int m, int n) {
            int[][] res = new int[m][n];

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0)
                        res[0][j] = 1;
                    else if (j == 0)
                        res[i][0] = 1;
                    else
                        res[i][j] = res[i - 1][j] + res[i][j - 1];
                }
            }
            return res[m - 1][n - 1];
        }