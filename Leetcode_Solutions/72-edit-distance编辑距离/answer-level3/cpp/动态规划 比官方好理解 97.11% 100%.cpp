### 解题思路
动态规划 比官方的好理解多了

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m*n == 0){
            return m+n;
        }
        
        int dp[m+1][n+1];
        for(int i=0; i<m+1; i++){
            dp[i][0] = i;
        }
        for(int j=0; j<n+1; j++){
            dp[0][j] = j;
        }
        
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
        return dp[m][n];
    }
};
```