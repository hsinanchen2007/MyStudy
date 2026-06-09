观察矩阵规律可以发现，**右上角和左下角**作为起始点都可以，如果目标数不满足其中一个方向，那就只能走另一个方向。
```
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix.size()==0||matrix[0].size()==0){
            return false;
        }
        int rows = matrix.size(), columns = matrix[0].size();
        int row = 0, column = columns - 1;
        while (row < rows && column >= 0) {
            int num = matrix[row][column];
            if (num == target) {
                return true;
            } else if (num > target) {
                column--;
            } else {
                row++;
            }
        }
        return false;
    }
};
```

