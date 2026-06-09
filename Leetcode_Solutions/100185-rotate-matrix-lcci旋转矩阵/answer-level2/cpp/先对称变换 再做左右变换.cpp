### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N/2; ++j) {
                swap(matrix[i][j], matrix[i][N - j - 1]);
            }
        }
        return;
    }
};
```