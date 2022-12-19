### 动态规划
我们使用动态规划数组dp[i][j]来表示字符串word1的前i个字符替换成字符串word2前j个所需要的最小步数。
（1）当第i个字符和第j个字符相等，即word1[i-1]==word2[j-1]时，无需做任何操作：dp[i][j]=d[i-1][j-1]
（2）当第i个字符和第j个字符不等时，即word1[i-1]!=word2[j-1]，取增，删，改查操作中所需要步骤数最小的那一个：
dp[i][j]=min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])
最后，返回dp[n1][n2]
### 时间/空间
时间：O(n1)
空间：O(n2)
### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<n1+1;++i){
            dp[i][0]=i;
        }
        for(int i=0;i<n2+1;++i){
            dp[0][i]=i;
        }
        for(int i=1;i<n1+1;++i){
            for(int j=1;j<n2+1;++j){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
            }
        }
        return dp[n1][n2];
    }
};
```