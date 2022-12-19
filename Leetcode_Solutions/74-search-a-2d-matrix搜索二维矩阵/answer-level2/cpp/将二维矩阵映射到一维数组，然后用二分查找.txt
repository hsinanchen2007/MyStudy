### 解题思路
。。。其实算法方面都没啥好讲的，基本如题。
映射方式见代码。感觉这题不配叫中等难度。

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
            return false;
        int rows = matrix.size(), cols = matrix[0].size(), vol = rows * cols;
        if(!vol)
            return false;
        if(matrix[rows - 1][cols - 1] == target || matrix[0][0] == target)
            return true;
        int left = 0, right = vol - 1, mid = left + right / 2;
        while(left < right - 1)
        {
            int i = mid / cols, j = mid % cols; // 将二维数组映射到一维上。
            if(matrix[i][j] > target)
            {
                right = mid;
                mid = (left + right) / 2;
            }
            else if(matrix[i][j] < target)
            {
                left = mid;
                mid = (left + right) / 2;
            }
            else
                return true;
        }
        return false;
    }
};
```