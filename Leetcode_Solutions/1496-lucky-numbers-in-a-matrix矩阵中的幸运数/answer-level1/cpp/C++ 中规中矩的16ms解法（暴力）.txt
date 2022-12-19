```cpp
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            int idx = 0, minm = matrix[i][0];
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] < minm) {
                    minm = matrix[i][j];
                    idx = j;
                }

            bool flag = true;
            for (int k = 0; k < m; ++k) 
                if (matrix[k][idx] > minm) {
                    flag = false;
                    break;
                }
            
            if (flag) {
                ans.push_back(minm);
                return ans;
            }
        }
        return ans;
    }
};
```