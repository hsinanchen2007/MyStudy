```cpp
class Solution {
private:
    vector<vector<int>> dp;
    int func(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 1;
        static int dx[] = {-1, 1, 0, 0};
        static int dy[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k ++) {
            int new_x = i + dx[k];
            int new_y = j + dy[k];
            if (0 <= new_x && new_x < matrix.size() && 0 <= new_y && new_y < matrix[0].size() &&
                matrix[new_x][new_y] > matrix[i][j])
                dp[i][j] = max(dp[i][j], func(new_x, new_y, matrix) + 1);
        }
        return dp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        dp = vector<vector<int>> (n, vector<int>(m, -1));
        int res = 0;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++) 
                res = max(res, func(i, j, matrix));
        return res;
    }
};

```