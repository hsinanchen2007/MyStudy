### 解题思路
c++  dp

### 代码

```cpp
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int lenA = A.size();
        int lenB = B.size();
        vector<vector<int>> dp(lenA+1, vector<int>(lenB+1, 0));
        for (int i = 0; i < lenA; i++) {
            for (int j = 0; j < lenB; j++) {
                if (A[i] == B[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[lenA][lenB];
    }
};
```