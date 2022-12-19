### 解题思路
1、初始化
1）字符串的操作需要考虑字符为空的情况，此时dp[0][0] = 0,word1[0]与word2[0]对应dp[1][1]。
2)若word1为空，此时dp[0][i]=i，即每次对word2进行增加操作；同理，word2为空，此时dp[i][0] = i,即每次对word1进行删除操作。
2、递归
1）若是s[i] == s[j], 此时i和j由于是相同的，不需要进行操作。dp[i][j] = dp[i-1][j-1]
2) 若s[i]-->s[j]需要增加，eg ab和abc：dp[i][j] = 1+dp[i][j-1]
   若s[i]-->s[j]需要删除，eg abcd和abc：dp[i][j] = 1+dp[i-1][j];
   若s[i]-->s[j]需要替换，eg abc和abd：dp[i][j] = 1+dp[i-1][j-1];

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j]表示从s[i-1]到p[j-1]需要的操作步数
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        dp[0][0] = 0;
        for(int i = 1; i<= n; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i<= m; i++){
            dp[i][0] = i;
        }
        for(int i = 1; i<= m; i++){
            for(int j = 1; j<= n;j++){
                if(word1[i-1] ==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) +1;
                }
            }
        }
        return dp[m][n];
    }
};
```