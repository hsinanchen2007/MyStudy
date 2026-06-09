### 解题思路
1. 动态规划, 递推公式为想等取左上+1, 不相等取max(左, 上).
2. 压缩空间复杂度, 因为只需要用到当前行和上一行的dp信息, 因此两个数组就可以推出所有信息.

### 代码

```cpp
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        // 同 1143. 最长公共子序列
        A.insert(A.begin(), 0);
        B.insert(B.begin(), 0);
        int dp[2][A.size()];
        memset(dp, 0, sizeof(dp));

        for (int y = 0; y < B.size(); y++) {
            for (int x = 0; x < A.size(); x++) {
                if (!A[x] || !B[y]) continue;
                if (A[x] == B[y]) dp[1][x] = dp[0][x - 1] + 1;
                else dp[1][x] = max(dp[0][x], dp[1][x - 1]);
            }
            memcpy(dp[0], dp[1], sizeof(dp[0]));
        }

        return dp[1][A.size() - 1];
    }
};
```