```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 直接使用最后一层三角形保存每层的路径和
        int n = triangle.size();
        for(int i = n-2; i >= 0; --i) {
            int curlen = triangle[i].size();
            for(int j = 0; j < curlen; ++j) {
                triangle[n-1][j] = min(triangle[n-1][j], triangle[n-1][j+1]) + triangle[i][j];
            }
        }
        return triangle[n-1][0];
    }
};
```
