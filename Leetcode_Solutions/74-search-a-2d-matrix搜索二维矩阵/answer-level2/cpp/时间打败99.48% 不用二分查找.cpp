### 解题思路
根据二维矩阵的特点，从右上开始遍历。

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0 ) return false;
        int hangsize = matrix.size();
        int liesize = matrix[0].size();

        int i = 0,j = liesize - 1;

        while(i < hangsize && j>= 0)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }    
            else if(matrix[i][j] < target)
            {
                i++;
            }else{
                j--;
            }
        }

        return false;
    }
};
```