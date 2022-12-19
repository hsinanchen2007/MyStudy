直接看代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int y = matrix.size();
        // 翻转
        for (int i = 0; i < y / 2; ++i) {
            swap(matrix[i], matrix[y - 1 - i]);
        }

        // 转置
        int x = y;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (i >= j) continue;
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
```