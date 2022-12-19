
状态定义：
dp[i][j] 表示text1[0~i-1]和text2[0~j-1]的最长公共子序列长度
dp[0][0]等于0，等于dp数组总体往后挪了一个，免去了判断出界
转移方程：
text1[i-1] == text2[j-1] 当前位置匹配上了: dp[i][j]=dp[i-1][j-1]+1 
text1[i-1] ！= text2[j-1] 当前位置没匹配上了 ：dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
basecase:
任何一个text长度为0时结果都是零，初始化时候就完成了basecase的赋值

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.length();
        int len2=text2.length();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i=1;i<len1+1;i++){
            for(int j=1;j<len2+1;j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};
```