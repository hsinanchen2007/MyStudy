### 解题思路

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int index1 = 0, index2 = matrix[0].size() - 1;
        for(int i = 0 ; i < matrix.size() ; ++i)
        {
            index1 = 0, index2 = matrix[0].size() - 1;
            while(index1 <= index2)
            {
                if(matrix[i][index1] == target || matrix[i][index2] == target)
                    return true;
                if(matrix[i][index1] < target)
                    index1++;
                if(matrix[i][index2] > target)
                    index2--;
            }
        }
        return false;
    }
};
```