### 解题思路

动态规划求最长公共子串

如果 s[i] == t[j], dp[i][j] = dp[i-1][j-1] + 1
如果 s[i] != t[j], dp[i][j] = 0

返回 dp[i][j]的最大值

### 代码

```cpp
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        int ans = 0;
        for (int i = 1; i < dp.size(); i++){
            for (int j = 1; j < dp[0].size(); j++){
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }   
        return ans;
    }
};
```