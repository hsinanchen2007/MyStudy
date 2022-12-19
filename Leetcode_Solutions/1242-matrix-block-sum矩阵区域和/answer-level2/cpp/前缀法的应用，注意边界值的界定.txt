### 解题思路
正如官方题解所说，本质上还是**前缀法**的应用。
要注意的是边界值的界定。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K) {
        if(mat.empty() || mat[0].empty() || K < 1) return mat;
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> sums(mat.size()+1, vector<int>(mat[0].size()+1, 0));
        for(int i = 1; i < sums.size(); i++){
            for(int j = 1; j < sums[0].size(); j++){
                sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + mat[i-1][j-1];
            }
        }
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[0].size(); j++){
                int up = (i-K >= 0)?(i-K):0;
                int down = (i+K < ans.size())?(i+K+1):ans.size();
                int left = (j-K >= 0)?(j-K):0;
                int right = (j+K < ans[0].size())?(j+K+1):ans[0].size();
                ans[i][j] = sums[down][right] - sums[down][left] - sums[up][right] + sums[up][left];
            }
        }
        return ans;
    }
};
```