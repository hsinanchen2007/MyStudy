### 解题思路
记录一下动态规划，若两个字符串当前字符相同，则dp[i][j]=dp[i-1][j-1],若不同：
```C++ []
1.若替换->dp[i][j]=dp[i-1][j-1]+1;
```
```C++ []
2.若增加A串->dp[i][j]=dp[i-1][j]+1;
```
```C++ []
3.若增加B串->dp[i][j]=dp[i][j-1]+1;
```
                                                            
三者取最小。

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i = 0;i<=len1;i++)
        {
            dp[i][0] = i;
        }
        for(int j = 0;j<=len2;j++)
        {
            dp[0][j] = j;
        }
        for(int i = 1;i<=len1;i++)
        {
            for(int j = 1;j<=len2;j++)
            {
                if(word1[i-1]!=word2[j-1])
                {
                     dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[len1][len2];
    }
};
```