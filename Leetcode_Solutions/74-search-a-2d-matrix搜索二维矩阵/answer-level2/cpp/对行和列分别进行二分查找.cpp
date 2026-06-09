### 解题思路
1. 首先对行进行二分查找，用每行最大值比对target，确定target大致所在的行
2. 再对该行进行按列二分查找

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size() - 1;
        int columns = matrix[0].size() - 1;
        int lr = 0, rr = rows;
        while (lr <= rr) {
            int mr = (lr + rr) / 2;
            if (target > matrix[mr][columns]) {
                lr = mr + 1;
            } else if (target < matrix[mr][columns]){
                rr = mr - 1;
            } else {
                return true;
            }
        }

        if (lr > rows) {
            return false;
        }

        int left = 0, right = columns;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[lr][mid] == target) {
                return true;
            } else if (matrix[lr][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
```