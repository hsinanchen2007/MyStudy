### 解题思路
动态规划
mm[i][j] = min(mm[i-1][j-1], mm[i][j-1], mm[i-1][j]) + 1;

### 代码

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<vector<int>> mm;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            vector<int> t(n, 0);
            mm.push_back(t);
        }
        int max_length = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != '1') continue;
                if (i * j == 0) {
                    mm[i][j] = 1;
                    max_length = max(max_length, mm[i][j]);
                    continue;
                }
                int min_length = min(mm[i-1][j-1], mm[i][j-1]);
                min_length = min(min_length, mm[i-1][j]);
                mm[i][j] = min_length + 1;
                max_length = max(max_length, mm[i][j]);
            }
        }
        return max_length * max_length;
    }
};
```