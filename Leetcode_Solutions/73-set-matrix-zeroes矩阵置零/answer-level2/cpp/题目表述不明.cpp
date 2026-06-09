### 解题思路
题目应该给个取值范围

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < matrix[0].size(); k++) {
                        if (matrix[i][k] != 0)
                            matrix[i][k] = -1000000;
                        else if (matrix[i][k] == -1000000)
                            break;
                    }
                    for (int k = 0; k < matrix.size(); k++) {
                        if (matrix[k][j] != 0)
                            matrix[k][j] = -1000000;
                        else if (matrix[k][j] == -1000000)
                            break;
                    }
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == -1000000)
                    matrix[i][j] = 0;
            }
        }
    }
};
```