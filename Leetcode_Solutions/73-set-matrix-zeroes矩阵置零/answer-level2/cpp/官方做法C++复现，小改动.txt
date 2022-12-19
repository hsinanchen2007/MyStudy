### 解题思路
第一个元素标0

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int line = matrix.size();
        int col = matrix[0].size();
        if (matrix.size() == 0) return;
        //两个bool用于第一行状态的描述
        bool firstline = false;
        bool firstcol = false;
        //第一行和第一列单独处理
        for (int i=0; i<line; i++) {
            if (matrix[i][0] == 0) {
                firstcol = true;
                break;
            }
        }
        for (int j=0; j<col; j++) {
            if (matrix[0][j] == 0) {
                firstline = true;
                break;
            }
        }
        //官方做法，第一位标0
        for (int i=1; i<line; i++) {
            for (int j=1; j<col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //检查第一行，查到0就更新一整列
        for (int i=1; i<line; i++) {
            if (matrix[i][0] == 0) {
                for (int j=1; j<col; j++) {
                    matrix[i][j] = 0;
                }                
            }
        }
        //检查第一列，查到0就更新所在行
        for (int j=1; j<col; j++) {
            if (matrix[0][j] == 0) {
                for (int i=1; i<line; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        //第一行第一列最后处理一下
        if (firstline) {
            for (int j=0; j<col; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstcol) {
            for (int i=0; i<line; i++) {
                matrix[i][0] = 0;
            }
        }        
    }
};
```