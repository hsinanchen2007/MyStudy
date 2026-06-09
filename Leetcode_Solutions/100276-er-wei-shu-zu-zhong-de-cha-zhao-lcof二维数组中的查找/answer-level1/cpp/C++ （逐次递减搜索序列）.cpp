### 解题思路
每一次循环与右上角的数进行比较。
若右上角数与目标数相等，返回true;
若右上角数大于目标数，舍弃该列，列数减1；
若右上角数小于目标数，舍弃该行，行数加一。

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row,col;
        row=matrix.size()-1;
        if(row>=0) 
            col=matrix[0].size()-1;
        else
            return false;
        int i=0,j=col;
        while(i<=row&&j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
```