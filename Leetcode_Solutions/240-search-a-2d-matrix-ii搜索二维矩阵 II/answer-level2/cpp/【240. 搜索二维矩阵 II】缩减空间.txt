## 思路
每次从右上角开始查找：
1. 若右上角数大于target，由于有序特性，则该列数都大于target，所以排除该列所有数；
2. 如果右上角数小于target，由于有序特性，则改行数都小于target，所以排除该行所有数；
3. 如果相等，则找到并停止查找。

**注意：判断空值**

### 代码
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //边界值
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int row = matrix.size(), col = matrix[0].size();
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                ++i;
            } else if (matrix[i][j] > target) {
                --j;
            }
        }
        return false;
    }
};
```
