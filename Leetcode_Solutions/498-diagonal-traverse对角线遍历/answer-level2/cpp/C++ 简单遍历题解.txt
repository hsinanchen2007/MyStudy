```C++ []
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int R = matrix.size();
        int C = matrix[0].size();
        int d = 1;
        vector<int> res;
        for (int s = 0; s < R + C; ++s) {
            int min_r = max(0, s - C + 1);
            int max_r = min(s, R - 1);
            if (d == 1) {
                for (int r = max_r; r >= min_r; --r) {
                    res.push_back(matrix[r][s - r]);
                }
            } else {
                for (int r = min_r; r <= max_r; ++r) {
                    res.push_back(matrix[r][s - r]);
                }
            }
            d ^= 1;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/96cfd74f997aa1bbbb47aff46664f021fe47bbb94f9fc57e4217885489a28a5f-image.png)
