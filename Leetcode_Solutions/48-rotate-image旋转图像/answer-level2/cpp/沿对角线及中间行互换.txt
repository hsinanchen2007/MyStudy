### 解题思路
1 2 3
4 5 6
7 8 9
1. 先沿对角线 7 5 3 互换
9 6 3
8 5 2
7 4 1
2. 再沿着中间线8 5 2 互换
7 4 1
8 5 2
9 6 3

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int num = matrix.size() - 1;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size() - i; ++j) {
                swap(matrix[i][j], matrix[num-j][num-i]);
            }
        }
        for (int i = 0; i < matrix.size() / 2; ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                swap(matrix[i][j], matrix[num-i][j]);
            }
        }
    }
};
```