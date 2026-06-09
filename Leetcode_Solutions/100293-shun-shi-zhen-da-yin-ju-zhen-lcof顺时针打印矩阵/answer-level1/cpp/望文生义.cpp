### 解题思路
如注释所述

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) return result;
        int t =  0, r = matrix[0].size() - 1, b = matrix.size() - 1, l = 0;
        while (true) {
            // 左往右
            for (int i = l; i <= r; ++i) result.push_back(matrix[t][i]);
            // 左往右，去掉一层的顶
            if (++t > b) break;

            // 上往下
            for (int i = t; i <= b; ++i) result.push_back(matrix[i][r]);
            // 上往下，去掉右边一列
            if (--r < l) break;

            // 右往左
            for (int i = r; i >= l; --i) result.push_back(matrix[b][i]);
            // 右往左，去掉下面一层
            if (--b < t) break;

            // 下往上
            for (int i = b; i >= t; --i) result.push_back(matrix[i][l]);
            // 下往上，去掉左边一列
            if (++l > r) break;
        }
        return result;
    }
};
```