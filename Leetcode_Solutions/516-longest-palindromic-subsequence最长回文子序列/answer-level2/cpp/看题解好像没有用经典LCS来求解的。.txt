### 解题思路
因为是子序列不是子串，所以可以逆置原字符串，采用最长公共子序列LCS来求解。
逆置后公共子序列就是回文子序列。

### 代码

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len=s.length();
        int dp[len+1][len+1];//代表A以i结尾的子串与B以j结尾的子串的最长公共子序列
        //LCS(最长公共子序列)字符串数组从1开始
        string A=" ";
        A+=s;
        std::reverse(s.begin(),s.end());
        string B=" ";
        B+=s;

        for(int i=0;i<=len;i++)//初始化边界
            dp[i][0]=0;
        for(int j=0;j<=len;j++)
            dp[0][j]=0;
        //状态转移方程
        //dp[i][j]=dp[i-1][j-1]+1; (A[i]==B[j])
        //dp[i][j]=max(dp[i-1][j],dp[i][j-1]); (A[i]!=B[j])
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                if(A[i]==B[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[len][len];

    }
};
```