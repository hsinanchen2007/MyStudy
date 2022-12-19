### 解题思路
三维dp数组，记录grid对应位置左连续1个数和上连续1个数
出过三次错误
错误1：没考虑当前位置minsize为0的情况，导致后续计算数组越界
错误2：对于当前节点，只判断了边长为minsize的情况，没有判断小于minsize，导致遗漏判断很多情况
错误3：对于minsize涉及到的节点，只考虑了等于，没考虑大于的情况，倒是遗漏很多符合的情况

### 代码

```cpp
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(2, 0)));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    dp[i][j][0] = i > 0 ? dp[i-1][j][0] + 1 : 1;
                    dp[i][j][1] = j > 0 ? dp[i][j-1][1] + 1 : 1;
                } else {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 0;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int minsize = min(dp[i][j][0], dp[i][j][1]);
                if (!minsize) continue;   // 错误1  minsize为0时忘记跳出，导致后面内存越界
                for (int k = minsize; k > 0; --k) { // 错误2 应该判断小于minsize的所有情况，而不是只判断minsize
                    if (k < result) break; // 优化1 k小于当前result时，直接跳出
                    if (dp[i-k+1][j][1] >= k && dp[i][j-k+1][0] >= k) {
                        result = max(result, k);
                        continue;
                    }
                }
            }
        }
        return result * result;
    }
};
```