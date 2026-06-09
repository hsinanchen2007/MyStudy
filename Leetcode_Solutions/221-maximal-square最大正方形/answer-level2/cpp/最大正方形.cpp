### 解题思路
此处撰写解题思路
dp[i][j] 表示以第i行，j列的点为正方形右下角的点的正方形的变长；
dp1[i][j] 表示该点左边1的个数；
dp2[i][j] 表示该点上边1的个数；

1 matrix[i][j] == '0': dp[i+1][j+1] = 0;
2 matrix[i][j] == '1': dp[i+1][j+1] = min3(1+dp[i][j], dp1[i+1][j+1], dp2[i+1][j+1]);
### 代码

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int column = matrix[0].size();
        if (column == 0){
            return 0;
        }

        // dp代表组成矩形的变长
        vector<vector<int> > dp(row+1, vector<int>(column+1, 0));
        // dp1 代表向左1的个数， dp2 代表向上1的个数
        vector<vector<int> > dp1(row+1, vector<int>(column+1, 0));
        vector<vector<int> > dp2(row+1, vector<int>(column+1, 0));
        dp1[0][0] = 0;
        dp2[0][0] = 0;
        dp[0][0] = 0;

        int max_area = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < column; ++j) {
                dp1[i+1][j+1] = ( (matrix[i][j] == '1') ? (dp[i+1][j] + 1) : 0 );
                dp2[i+1][j+1] = ( (matrix[i][j] == '1') ? (dp[i][j+1] + 1) : 0 );
                if(matrix[i][j] == '1') {
                    dp[i+1][j+1] = min3(1+dp[i][j], dp1[i+1][j+1], dp2[i+1][j+1]);
                }
                max_area = max(max_area, dp[i+1][j+1] * dp[i+1][j+1]);
            }
        }
        return max_area;
    }

    int min3(const int& a, const int& b, const int& c){
        int tmp = (a < b)? a: b;
        return (tmp < c)? tmp: c;
    }
};
```