最近做的DP的题目有点多，遇到关于字符串的DP的问题仿佛都是要建一个m*n的dp数组，这仿佛是一点经验。

首先题目要的是 在字符串S中有多少子串和字符串t相等，则题目便有一个前提条件 t.length() <= s.length()

则令 m=t.length() n=s.length()，dp[i][j]意味着子问题 字符串 s.substr(j)中包含多少子串和 t.substr(i)相等

最后返回dp[m][n]就是该题目的解

下一步我们讨论动态方程如何定义，第一点很容易明白，显而易见 若 i>j ，则dp[i][j]=0 ；

若 i==j && s[j]==t[i] 则 dp[i][j]=dp[i-1][j-1]
若 i< j && s[j]==t[i] 则 dp[i][j]=dp[i-1][j-1] + dp[i-1][j-1] ;
(其实这两步可以合在一起，因为 i==j 时 dp[i-1][j-1]==0 ,为了方便理解把他拆开)

否则 dp[i][j]=dp[i][j-1]

下面解释一下第二点，其实举个例子很容易明白是组合数的关系
  
x 0 b b b
0 1 1 1 1          (初始化dp矩阵，空字符可以被空字符匹配上)
b 0 1 2 3
b 0 0 1 3 

其中 dp[i-1][j-1]是选取s中第j个字符来匹配t中第i个字符的数目
     dp[i][j-1] 是不选取s中第j个字符, 而是前j个字符中能够匹配t中前i的字符的数目

那么最后一点dp[i][j]=dp[i][j-1]也就很好解释了，遇到s[j]!=t[i]，则把前面匹配上的数目向后记录下来，便于累加。

附上c++的代码

class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        long long **dp=new long long *[m+1];
        for(int i=0;i<m+1;i++)
            dp[i]=new long long [n+1];
        for(int i=0;i<n+1;i++)
            dp[0][i]=1;
        for(int i=1;i<m+1;i++)
            dp[i][0]=0;
        for(int i=1;i<m+1;i++)
            for(int j=1;j<n+1;j++)
            {
                if(j<i)
                    dp[i][j]=0;
                else if(i==j && t[i-1]==s[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else if(j>i && t[i-1]==s[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                else 
                    dp[i][j]=dp[i][j-1];
            }
        return dp[m][n];

    }
};