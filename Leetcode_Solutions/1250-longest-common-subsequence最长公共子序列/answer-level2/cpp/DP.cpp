### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        if (!len1 || !len2) {
            return 0;
        }
        int dp[len1+1][len2+1]; //dp[i][j]表示text1[0...i]和text2[0...j]最长公共子序列的长度
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                //text的下标和dp的下标含义不同
                if(text1[i-1]==text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {                   
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];

    }
};
```