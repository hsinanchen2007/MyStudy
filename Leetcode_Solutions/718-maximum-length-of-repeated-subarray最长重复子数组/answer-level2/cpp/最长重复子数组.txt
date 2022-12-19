### 解题思路
if (A[i] == B[j]) dp[i+1][j+1] = 1+dp[i][j];

### 代码

```cpp
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n1 = A.size();
        int n2 = B.size();
        vector<vector<int> >dp(n1+1, vector<int>(n2+1, 0));
        for(int i = 0; i < n1; ++i) {
            if ( A[i] == B[0]) {
                dp[i+1][1] = 1;
            }
        }
        for(int j = 0; j < n2; ++j) {
            if ( B[j] == A[0]) {
                dp[1][j+1] = 1;
            }
        }
        for(int i = 0; i < n1; ++i) {
            for(int j = 0; j < n2; ++j) {
                if (A[i] == B[j]) {
                    dp[i+1][j+1] = 1+dp[i][j];
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= n1; ++i) {
            for(int j = 1; j <= n2; ++j) {
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }   
};
```