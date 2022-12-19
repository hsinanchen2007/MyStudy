1.先计算出562. 矩阵中最长的连续1线段矩阵
2.DP求解对角线最大
```
/*
* Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: i love leetcode
* Author: Nicolas
* Create: 2019/10/19
*/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B)
    {
        int m = A.size();
        int n = B.size();
        if (m == 0 || n == 0) {
            return 0;
        }

        vector<vector<int>> matrix(A.size(), vector<int>(B.size(), 0));
        buildRoad(m, n, matrix, A, B);
        return diagonalMax(m, n, matrix);
    }

private:
    void buildRoad(int m, int n, vector<vector<int>> &matrix, vector<int> &A, vector<int> &B)
    {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = (A.at(i) == B.at(j) ? 1 : 0);
            }
        }
    }

    int diagonalMax(int m, int n, vector<vector<int>> &matrix)
    {
        int maxLength = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] += dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                }
            }
        }
        return maxLength;
    }

};
```
