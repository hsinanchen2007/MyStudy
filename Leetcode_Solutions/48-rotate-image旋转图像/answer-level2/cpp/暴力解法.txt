### 解题思路
矩阵旋转的替换规则：
a[i][j]->a[j][n - i - 1]-> a[n - i -1][n - j - 1]->a[n - j - 1][i]->a[i][j]
![matrix_rotation.jpg](https://pic.leetcode-cn.com/9fdb3fe8ae71275dcd6051235599b54aafe7d4dc7ef4f21a700055da2728cf8e-matrix_rotation.jpg)

此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    //row i -> col n - i - 1
    //col j -> row j
    //a[i][j]->a[j][n - i - 1]-> a[n - i -1][n - j - 1]->a[n - j - 1][i]->a[i][j]
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int m, n;
        int temp;
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return;
        }

        m = matrix.size();
        n = matrix[0].size();

        for(i = 0; i <= m - 2; i++)
        {
            for(j = i; j < n - i - 1; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};
```