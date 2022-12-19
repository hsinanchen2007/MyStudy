### 解题思路
二分法： 先在第一列上进行二分法，确定在第几行，然后再在改行进行二分法

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 二分法： 先在第一列上进行二分法，确定在第几行，然后再在改行进行二分法。
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        // 列二分法
        int row = 0;
        int top = 0;
        int down = matrix.size() - 1;
        if (matrix[0][0] > target)
            return false;
        while (top <= down) {
            int middle = (top + down) / 2;
            if (matrix[middle][0] == target) {
                return true;
            } else if (matrix[middle][0] < target) {
                top++;
            } else {
                if (middle == 0) {
                    row = 0;
                    break;
                } else if (matrix[middle-1][0] < target) { // 使得matrix[middle-1] < target, matrix[middle] > target; 确定row
                    row = middle - 1;
                    break;
                } else {
                    down--;
                }
            }
        }

        if (top == matrix.size())
            row = matrix.size() - 1;
        
        // 行二分法
        int left = 0;
        int right =  matrix[0].size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (matrix[row][middle] == target)
                return true;
            else if (matrix[row][middle] < target)
                left++;
            else
                right--;
        }

        return false;
    }
};
```