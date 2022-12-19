### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int dp[len1 + 1][len2 + 1];
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= len2; i++){
            dp[0][i] = dp[0][i - 1] + 1;
        }
        for(int j = 1; j <= len1; j++){
            dp[j][0] = dp[j - 1][0] + 1;
        }
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else
                dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]),dp[i][j - 1]) + 1;
            }
        }
        return dp[len1][len2];
    }
};


 
```