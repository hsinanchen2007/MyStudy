![image.png](https://pic.leetcode-cn.com/036f1b538025acc14e6b6cde3a7eda95f5846f6cc52aec6ab7ca79f526a9935d-image.png)

### 代码

用u, d, l, r四个变量来维护可行边界

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ret;
        int u = 0, d = n - 1, l = 0, r = m - 1;
        while (true) {
            for (int j = l; j <= r; j++) ret.push_back(matrix[u][j]);
            if (++u > d) break;
            for (int i = u; i <= d; i++) ret.push_back(matrix[i][r]);
            if (--r < l) break;
            for (int j = r; j >= l; j--) ret.push_back(matrix[d][j]);
            if (--d < u) break;
            for (int i = d; i >= u; i--) ret.push_back(matrix[i][l]);
            if (++l > r) break;
        }
        return ret;
    }
};
```