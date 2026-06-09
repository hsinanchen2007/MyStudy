### 解题思路
只需要列出原来的数组和旋转后的数组；
然后找到数组规律，新的数组tmp[j][size - i] = matrix[i][j];
转换后再把tmp赋值给matrix。

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        if (size == 0) return;
        vector<vector<int>> tmp(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                tmp[j][size - i - 1] = matrix[i][j];
            }
        }
        matrix = tmp;
    }
};
```