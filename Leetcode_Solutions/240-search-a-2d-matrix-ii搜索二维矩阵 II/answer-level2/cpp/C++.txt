### 解题思路
从左上角开始遍历，利用有序性

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size();
        if (height == 0) {
            return false;
        }
        int width = matrix[0].size();
        int i = 0;
        int j = width -1;
        while (i <= height - 1 && j >= 0) {
            int num = matrix[i][j];
            if (num == target) {
                return true;
            } else if (num > target) {
                j--;
            } else if (num < target) {
                i++;
            }
        }
        return false;
    }
};
```