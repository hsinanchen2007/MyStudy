### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if(matrix.empty())
        return false;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i = rows - 1;
    int j = 0;
    while(i >= 0 && j <= cols-1)
    {
        if(target == matrix[i][j])
            return true;
        else if(target > matrix[i][j])
            j++;
        else
            i--;
    }
    return false;     
    } 
};
```