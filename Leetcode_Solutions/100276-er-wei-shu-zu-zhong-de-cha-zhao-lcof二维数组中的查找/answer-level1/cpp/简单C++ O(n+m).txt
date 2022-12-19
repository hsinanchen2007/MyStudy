### 解题思路
因为数组元素之间的特殊关系，从左至右，从上至下都是递增的，因此我们从右上角开始，小于target则往左遍历，大于target则往右遍历，遍历完还没有则返回false.

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() < 1)
            return false;
        int n = matrix.size();
        int i = 0, j = matrix[0].size() - 1;
        while(i < n && j >= 0) {
            if(target == matrix[i][j])
                return true;
            else if(target > matrix[i][j])
                ++i;
            else
                --j;
        }
        return false;
    }
};
```