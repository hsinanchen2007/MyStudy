### 解题思路
虽然不是最好的解，但是这个解
![image.png](https://pic.leetcode-cn.com/7e5df27620b1c4bf0ea4dd23154e3b192a7a064c7e3afe8065b4064956ac3bb0-image.png)
感觉还行

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int line_len = matrix.size();
        int row_len = matrix[0].size();
        vector<int> line(line_len, -1);
        vector<int> row(row_len, -1);
        for (int i = 0; i < line_len; ++i)
        {
            for(int j = 0; j < row_len; ++j)
                if (matrix[i][j] == 0)
                {
                    line[i] = 1;
                    row[j] = 1;
                }
        }
        for (int i = 0; i < line_len; ++i)
        {
            if (line[i] == 1)
                for(int j = 0; j < row_len; ++j)
                    matrix[i][j] = 0;
        }
        for (int i = 0; i < row_len; ++i)
        {
            if (row[i] == 1)
                for(int j = 0; j < line_len; ++j)
                    matrix[j][i] = 0;
        }
    }
};
```