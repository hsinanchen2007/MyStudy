### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word2.size(),n=word1.size();
        int dp[n+1][m+1];//处理空字符串的情况；
        for(int i=0;i<n+1;i++)
        {
           for(int j=0;j<m+1;j++)
           {
               if(i==0||j==0) dp[i][j]=i+j;
               else{
                   if(word1[i-1]==word2[j-1])
                     dp[i][j]=dp[i-1][j-1];
                    else
                      dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
               }
           }
        }
        return dp[n][m];
    }
};
```