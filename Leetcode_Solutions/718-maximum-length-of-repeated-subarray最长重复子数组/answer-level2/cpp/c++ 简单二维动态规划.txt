### 解题思路
模板类型的题

### 代码

```cpp
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        if(M == 0 || N == 0) return 0;
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        int max_length = 0;
        for(int i = 1; i <= M; i++){
            for(int j = 1; j <= N; j++){
                if(A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    max_length = max(max_length, dp[i][j]);
                }
            }
        }
        return max_length;
    }
};
```