### 解题思路

### 代码

```cpp
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ans = 0;
        int n = A.size(), m = B.size();
        int dp[n][m] = {0};
        for(int i = 0 ; i < m ; ++i)
        {
            if(B[i] == A[0])
                dp[0][i] = 1;
        }
        for(int i = 0 ; i < n ; ++i)
        {
            if(A[i] == B[0])
                dp[i][0] = 1;
        }
        for(int i = 1 ; i < n ; ++i)
        {
            for(int j = 1 ; j < m ; ++j)
            {
                if(A[i] == B[j])
                {
                    if(A[i - 1] == B[j - 1])
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                        dp[i][j] = 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
```