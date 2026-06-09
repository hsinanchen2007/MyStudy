### 解题思路
1. 要想走到终点，Path(m, n) = Path(m - 1, n) + Path(m, n - 1)，如此重复递归
2. 为避免重复计算导致超时，需要使用临时表记录下已经计算过路径
### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m + 1, vector<int>(n + 1, 0));
        return uniquePaths(m, n, path);
    }
    
    int uniquePaths(int m, int n, vector<vector<int>>& path) {
        if (m <= 0 || n <= 0) {
            return 0;
        }

        if (m == 1 || n == 1) {
            return 1;
        }

        // 查找记录表，避免重复计算
        if (path[m][n] != 0) {
            return path[m][n];
        }

        int down = uniquePaths(m - 1, n, path);
        int right = uniquePaths(m, n - 1, path);
        path[m - 1][n] = down;
        path[m][n - 1] = right;
        path[m][n] = down + right;
        return  down + right;
    }
};
```