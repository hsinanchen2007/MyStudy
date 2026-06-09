### 解题思路
除第0行和第0列，每个元素与对应左上角元素比较

### 代码

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        if(matrix.size()==1 || matrix[0].size()==1)
        return true;
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][j]!=matrix[i-1][j-1])
                return false;
            }
        }
        return true;
    }
};
```