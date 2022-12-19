```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;
        int l = 0, r = m - 1, u = 0, d = n - 1;
        while (true) {
            for (int k = l; k <= r; k ++) ans.push_back(matrix[u][k]);
            if (++ u > d) break;
            for (int k = u; k <= d; k ++) ans.push_back(matrix[k][r]);
            if (-- r < l) break;
            for (int k = r; k >= l; k --) ans.push_back(matrix[d][k]);
            if (-- d < u) break;
            for (int k = d; k >= u; k --) ans.push_back(matrix[k][l]);
            if (++ l > r) break;
        }   
        return ans;
    }
};
```