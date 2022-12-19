### 解题思路
第一感觉：把p串逐步缩小来解决问题，怎么缩小？那一个一个字符来分析吧
p会有哪些字符？.  *  a-z
如果现在p[j]=='.',那么对于要匹配到s[i]的s的子串，怎么判断他们是否匹配？
答:如果p[j-1]之前的字串和s[i-1]的字串匹配上了，那么p[j]和s[i]就匹配上了
通过这个问题，我们就可以得到dp数组和分析状态转移方程的思路了
同理就是p[j]=='*'的时候怎么办？要分情况了：1.如果这个*选择重复0次字符，则要考虑s[i]和p[j-2]；2.如果*前面是'.'那怎么考虑？3.如果是a-z，那又怎么考虑？
最后再提一点。。*的三种情况只要有一种可行，那整体就是可行的。

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int si = s.size();
        int pi = p.size();
        vector<vector<int>> dp(si + 5, vector<int>(pi + 5));
        dp[0][0] = true;
        for (int i = 0; i <= si; i++)
        {
            for (int j = 1; j <= pi; j++)
            {
                if (p[j - 1] == '*')
                {
                    if (dp[i][j - 2] == 1) //表示这个*取0个元素
                    {
                        dp[i][j] = 1;
                    }
                    else if (p[j - 2] == '.') //这个*前面是.可以重复任意元素
                    {
                        if (i > 0 && dp[i - 1][j] == 1)
                        {
                            dp[i][j] = 1;
                        }
                    }
                    else if (i > 0 && s[i - 1] == p[j - 2])
                    {
                        if (dp[i - 1][j] == 1)
                        {
                            dp[i][j] = 1;
                        }
                    }
                }
                else
                {
                    if (p[j - 1] == '.')
                    {
                        if (i > 0 && dp[i - 1][j - 1])
                        {
                            dp[i][j] = 1;
                        }
                    }
                    else
                    {
                        if (i > 0 && s[i - 1] == p[j - 1] && dp[i - 1][j - 1] == 1)
                        {
                            dp[i][j] = 1;
                        }
                    }
                }
            }
        }
        return dp[si][pi];

    }
};
```