### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int a = matrix.size();
        int b = matrix[0].size();
        for(int i = 0; i < a - 1; i++)
        {
            for(int j = 0; j < b - 1; j++)
            {
                if(matrix[i][j] != matrix[i+1][j+1])
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};
```