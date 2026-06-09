### 解题思路
记录height, left, right数组，每行根据上一行进行更新。

### 代码

```cpp
class Solution {
public:
int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0) return 0;
    int m, n;
    m = matrix.size(), n = matrix.back().size();
    vector<int> left(n, 0), right(n, n), height(n, 0);
    int maxarea = 0;
    for (int i = 0; i < m; ++i) {
        int cur_left = 0, cur_right = n;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '1') height[j] += 1;
            else height[j] = 0;
        }
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '1') left[j] = max(left[j], cur_left);
            else {
                left[j] = 0;
                cur_left = j + 1;
            }
        }
        for (int j = n - 1; j >= 0; --j) {
            if (matrix[i][j] == '1') right[j] = min(right[j], cur_right);
            else {
                right[j] = n;
                cur_right = j;
            }
        }
        for (int j = 0; j < n; ++j) {
            maxarea = max(maxarea, height[j] * (right[j] - left[j]));
        }

    }
    return maxarea;
}
};
```