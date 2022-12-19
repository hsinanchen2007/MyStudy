### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp;
        //转置
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = i+1; j < matrix[i].size(); ++j)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        //翻转
        for(int i = 0; i < matrix.size(); ++i)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```