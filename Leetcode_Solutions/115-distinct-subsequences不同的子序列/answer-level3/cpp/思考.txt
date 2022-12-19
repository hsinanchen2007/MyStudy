### 解题思路
动态规划的题目，首先找到递推公式：
dp[i][j]表示字符串T的从0开始长度为i的子串和字符串S的从0开始长度为j的子串的匹配总个数。(s的长度时大于等于t的，否则输出为0） 
设置一个dp[t.length+1][s.length+1]  
初始化情况： 
首先dp[0][0]=1；表示空的字符串t和空的字符串s是匹配的。 
然后dp[0][1….s.length]=1；表示的是空的字符串t，与不为空的字符串s是相互匹配的，而且匹配的个数为1。 
dp[1…..t.length][0]=0; 表示不为空的字符串t， 空的字符串s，他们匹配的总个数为0；

当t[i-1]==s[j-1]相同时：　dp[i][j]=dp[i-1][j-1]+dp[i][j-1] 
当t[i-1]!=s[j-1]不相同: dp[i][j]=dp[i][j-1]。

最后输出dp[t.length][s.length]


### 代码

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int l1 = t.size();
        int l2 = s.size();
        long dp[l1 + 1][l2 + 1];
        for(int i = 0; i< l2 + 1; i++)  //首先i对于的就是字符串t里面的索引
        {
            dp[0][i] = 1;
        }
        for(int i = 1; i < l1 + 1; i++)  //首先从第二行开始计算，第一行中第一个数总是为1的。
        {
            dp[i][0] = 0;
        }
        for(int i = 1; i <= l1; i++)     //动态规划
        {
            for(int j = 1; j <= l2; j++) //首先j对于的就是字符串s里面的索引。（s>t）
            {
                if(t[i - 1] != s[j - 1])
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else
                {
                     dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                }
            }

        }
        return dp[l1][l2];
    }
};
```