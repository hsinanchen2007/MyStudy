### 解题思路
顺时针90°：沿45°对角线翻转，再上下翻转
逆时针90°：沿-45°对角线翻转，再上下翻转
旋转180°：沿45°对角线翻转，再沿-45°对角线翻转

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n < 2) return;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n-1-i; j++) {
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
        }
        for (int i = 0; i <= (n - 1)/2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
        

    }
};
```