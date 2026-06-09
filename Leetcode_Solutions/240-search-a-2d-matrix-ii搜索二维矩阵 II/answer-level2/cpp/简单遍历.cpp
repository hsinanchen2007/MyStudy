### 解题思路


### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int j = matrix[0].size() - 1;
        int i = 0;
        while(j >= 0 && i < matrix.size())
        {
            if(target < matrix[i][j])
                j--;
            else if(target > matrix[i][j])
                i++;
            else
                return true;
        }
        return false;
    }
};
```