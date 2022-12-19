### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int nRow = matrix.size();
        if(nRow <= 1)
            return ;
        std::vector< vector<int> > tmp;
        tmp.resize(nRow);
        for(auto i = 0;  i < nRow; ++i)
        {
            tmp[i].resize(matrix[i].size());
        }

        for(auto i = 0; i < matrix[0].size(); ++i)
        {
            for(auto j = 0; j < nRow; ++j)
            {
                tmp[i][j] = matrix[i][j];
            }
        }
        for(auto i = 0;  i < matrix[0].size(); ++i)
        {
            for(auto j = 0; j < nRow; ++j)
            {
               
                matrix[j][nRow - 1 - i] = tmp[i][j];
            }
        }
    }
};
```