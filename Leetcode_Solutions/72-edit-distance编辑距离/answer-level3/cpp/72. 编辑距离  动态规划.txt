### 解题思路


### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m,n;
        m=word1.size();n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m+1;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<n+1;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                int left=dp[i][j-1]+1;
                int right=dp[i-1][j]+1;
                int left_right=dp[i-1][j-1];
                if(word1[i-1]!=word2[j-1]) left_right=dp[i-1][j-1]+1;
//注意是i-1不是i，因为这里i表示的是第几个字符，对应下标要减一
                dp[i][j]=min(left,min(right,left_right));
            }
        }
        return dp[m][n];
    }
};
```