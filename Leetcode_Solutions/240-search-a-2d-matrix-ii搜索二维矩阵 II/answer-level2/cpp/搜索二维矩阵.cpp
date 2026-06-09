仔细观察矩阵左下角或者右上角，对于左下角，往右走数字变大，往上走数字变小，
那么我们从左下角出发，target比当前值大，我们就往右走，target比当前值小，我们就往上走，若target存在一定会找到

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int i = matrix.size() - 1;
        int j = 0;
        while(i >= 0 && j < matrix[0].size()){
            if(matrix[i][j] > target)
                --i;
            else if(matrix[i][j] < target)
                ++j;
            else return true;
        }
        return false;
    }
};
```