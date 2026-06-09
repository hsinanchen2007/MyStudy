### 解题思路
1. 根据矩阵上下左右已序的条件，设置起始/结束行，起始/结束列
2. 使用target比对矩阵4个顶点，根据大小，调整起始/结束的行和列，从而缩小搜索范围

### 代码
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size() - 1, cols = matrix[0].size() - 1;
        int sr = 0, sc = 0;
        while (sr <= rows && sc <= cols) {
            if (target < matrix[sr][sc] || target > matrix[rows][cols]) {
                return false;
            }
            if (target > matrix[sr][cols]) {
                ++sr;
                continue;
            } else if (target < matrix[sr][cols]) {
                --cols;
                continue;
            }
            if (target > matrix[rows][sc]) {
                ++sc;
                continue;
            } else if (target < matrix[rows][sc]) {
                --rows;
                continue;
            }
            return true;
        }
        return false;
    }
};
```