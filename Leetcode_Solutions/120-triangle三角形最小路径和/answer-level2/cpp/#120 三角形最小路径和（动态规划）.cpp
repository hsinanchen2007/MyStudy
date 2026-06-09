### 代码
```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> res(triangle.size());
        res[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            res[i] = res[i-1] + triangle[i][i];
            for (int j = i-1; j >= 1; j--) {
                res[j] = min(res[j], res[j-1]) + triangle[i][j];
            }
            res[0] = res[0] + triangle[i][0];
        }
        return *min_element(res.begin(), res.end());
    }
};
```