主要思路：求出(0,0)到(m,n)的所有元素的前缀和dp[i][j](i,j为当前元素位置);然后再通过dp[i][j]与周围点的关系dp[i][j - k - 1]，dp[i - k - 1][j - k - 1]，求出交叠区域的面积，如果面积是平方数，则说明为题目要求的正方形区域（dp[i][j] - left - up + upperLeft）

int countSquares(vector<vector<int> > &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > dp(row, vector<int>(col, 0));  // dp(i,j)从位置(0,0)至(i,j)的元素和

        // 求前缀和
        dp[0][0] = matrix[0][0];
        for (int i = 1; i < col; i++) {
            dp[0][i] = dp[0][i - 1] + matrix[0][i];
        }

        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i][j];
            }
        }

        int squreLen = min(row, col);
        int count = 0;  // 正方形个数
        for (int k = 0; k < squreLen; k++) {
            int area = pow(k + 1, 2);  // 实际正方形边长为 k + 1
            for (int i = k; i < row; i++) {
                for (int j = k; j < col; j++) {
                    // 当前位置的左侧位置
                    int left = 0;
                    if (j - k - 1 >= 0) {
                        left = dp[i][j - k - 1];
                    }

                    // 当前位置的上方位置
                    int up = 0;
                    if (i - k - 1 >= 0) {
                        up = dp[i - k - 1][j];
                    }

                    // 左侧位置和右侧位置的交叠区域
                    int upperLeft = 0;
                    if ((i - k - 1 >= 0) && (j - k - 1 >= 0)) {
                        upperLeft = dp[i - k - 1][j - k - 1];
                    }

                    // 当前位置的区域和应该和正文形面积相等
                    // int tmp = dp[i][j] - left - up + upperLeft;
                    if (area == (dp[i][j] - left - up + upperLeft)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }