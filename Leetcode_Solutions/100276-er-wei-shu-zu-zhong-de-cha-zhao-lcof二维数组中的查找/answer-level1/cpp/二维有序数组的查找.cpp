### 解题思路
由于数据是有序的，所以应从右上角或左下角开始遍历。当前值如果小于目标值，说明以当前值为行的向量是没有必要进行遍历的，当前值如果大于目标值，说明以当前值为列的列向量是没有必要遍历的。利用有序的这种性质，每次都可以减少一行或者一列的数据。

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0, j = col-1; (i<row && j>=0); ){
            if (matrix[i][j] == target)
                return true;
            else if(matrix[i][j]>target)
                j--;
            else
                i++;
        }
        return false;
    }
};
```