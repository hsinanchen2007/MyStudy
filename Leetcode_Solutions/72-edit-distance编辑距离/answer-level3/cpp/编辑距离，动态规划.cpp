### 解题思路
记dp[i][j]为word1的前i个(下标[0,i-1])和word2的前j个(下标[0,j-1])的最小编辑距离
那么对于dp[i+1][j+1]，我们比较word[i]和word[j]的值
若两者相等，说明不需要编辑，dp[i+1][j+1] = dp[i][j]
若两者不等，可以进行三种编辑：
word1删去word1[i]，对应dp[i+1][j+1] = dp[i][j+1] + 1
word1插入word2[j],对应dp[i+1][j+1] = dp[i+1][j] + 1
word1和word2两者都进行替换，对应dp[i+1][j+1] = dp[i][j] + 1
取三者最小值即可

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i = 0;i <= len1;++i)
            dp[i][0] = i;
        for(int i = 0;i <= len2;++i)
            dp[0][i] = i;
        for(int i = 1;i <= len1;++i){
            for(int j = 1;j <= len2;++j){
                if(word1[i-1] != word2[j-1])
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[len1][len2];
    }
};
```