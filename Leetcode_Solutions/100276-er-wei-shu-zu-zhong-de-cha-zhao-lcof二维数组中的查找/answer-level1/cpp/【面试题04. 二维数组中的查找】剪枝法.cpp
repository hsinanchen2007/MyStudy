## 思路
根据数组特性，可以从左下角或右上角的元素开始查找，如果不等于target，可以直接减少一行或一列的查找。

### 代码
时间复杂度：O(n + m)
空间复杂度：O(1)
```c++
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int row = matrix.size(), col = matrix[0].size();
        int i = row - 1, j = 0;
        while (i >= 0 && j < col) {
            if (target == matrix[i][j]) return true;
            else if (target < matrix[i][j]) --i;
            else ++j;
        }
        return false;
    }
};
```

### 另一种写法
```c++
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int row = matrix.size(), col = matrix[0].size();
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            if (target == matrix[i][j]) return true;
            else if (target < matrix[i][j]) --j;
            else ++i;
        }
        return false;
    }
};
```
