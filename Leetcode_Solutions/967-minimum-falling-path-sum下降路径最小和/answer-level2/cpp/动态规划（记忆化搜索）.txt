### 解题思路
从第零行开始，按照列开始遍历，典型的动态规划 记忆化搜索，注意递归的下一个index，还有递归终止条件。

### 代码

```cpp
class Solution {
public:
    int DFSGetMinDp(vector<vector<int>>& A, vector<int>& minDp, int line, int col) 
    {
        if (minDp[line*A.size() + col] != INT_MAX) {
            return minDp[line*A.size() + col];
        }
        if (line == A.size() - 1) {
            minDp[line*A.size() + col] = A[line][col];
        } else if (line < A.size() - 1) {
            int results = INT_MAX;
            for (int i = -1; i <= 1; i++) {
                if (col + i >= 0 && col + i <= A.size() - 1) {
                    results = min(results, DFSGetMinDp(A, minDp, line + 1, col + i));
                }
            }
            minDp[line*A.size() + col] = results + A[line][col];
        }
        return minDp[line*A.size() + col];
    }

    int minFallingPathSum(vector<vector<int>>& A) {
        vector<int> minDp(A.size() * A[0].size(), INT_MAX);
        int results = INT_MAX;
        for (int i = 0; i < A.size(); i++) {
            results = min(results, DFSGetMinDp(A, minDp, 0, i));
        }
        return results;
    }
};
```