### 解题思路
45°翻转，再上下翻转

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                swap(matrix[j][i], matrix[n-i-1][n-j-1]);
            }
        }
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }       

    }
};
```