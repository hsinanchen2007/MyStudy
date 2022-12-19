### 解题思路
这道题和剑指offer的19题一样。。
1.是动态规划。 没看懂。。。
2.是相对于3简化一点的方法。把重复的步骤去掉了。  
3.剑指offer上的答案写上来超时了。后来发现是判断条件不一样if((p[pb]==s[sb]||(p[pb]=='.')&&s[sb]!='\0'))。剑指offer上会做很多重复计算。


### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int sSize = int(s.size());
        int pSize = int(p.size());
        if (p.empty())
        {
            return s.empty();
        }
        vector<bool> tmpVec(pSize + 1, false);//dp大小应该比s，p的size大1
        vector<vector<bool>> dp(sSize + 1, tmpVec); //dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配
        dp[0][0] = true;
        if (sSize != 0 && (p[0] == s[0] || p[0] == '.'))
        {
            dp[1][1] = true;
        }
        if (p[0] == '*')
        {
            dp[0][1] = true;
        }
        //初始化情况：s为空，p为.*.*的情况
        for (int i = 1; i < pSize; i++)
        {
            if (p[i] == '*' && dp[0][i - 1] == true)
            {
                dp[0][i + 1] = true;
            }
        }

        for (int i = 0; i < sSize; i++)
        {
            for (int j = 1; j < pSize; j++)
            {
                if (p[j] == '.' || p[j] == s[i])
                { //如果是任意元素 或者是对于元素匹配
                    dp[i + 1][j + 1] = dp[i][j];
                }
                if (p[j] == '*')
                {
                    //caa cb* -> caa c
                    if (p[j - 1] != s[i] && p[j - 1] != '.')
                    { //如果前一个元素不匹配 且不为任意元素
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    }
                    else
                    {
                        //caa c.* -> ca c.*
                        //caa ca* -> ca ca*
                        //ca ca* -> ca ca / c ca*
                        //ca ca*a* -> ca ca*
                        dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j - 1]);// || dp[i + 1][j]不需要
                    }
                }
            }
        }
        //print(dp);
        return dp[sSize][pSize];
    }

    // 执行用时 :4 ms, 在所有 C++ 提交中击败了96.37% 的用户
    // 内存消耗 :8.3 MB, 在所有 C++ 提交中击败了86.79%的用户


    bool isMatch(string s, string p) {
        return doMatch(s, 0, p, 0);
    }
     bool isMatchCore(const string& s, int sIndex, const string& p, int pIndex)
    {
		if (pIndex >= p.size()) return sIndex >= s.size();

		bool currentMatch = sIndex < s.size() && (s[sIndex] == p[pIndex] || p[pIndex] == '.');

        if(pIndex + 1 < p.size() && p[pIndex + 1] == '*')
        {
			// *匹配0个字符(无论当前字符匹不匹配这都有可能s = abbc, p = ab*bbc) || 当前字符匹配并尝试s中的下一个字符
			return isMatchCore(s, sIndex, p, pIndex + 2) || (currentMatch && isMatchCore(s, sIndex + 1, p, pIndex));
        }
        else // 没有*
        {
			// 正常匹配，包括了.
            // 匹配上就考察下一个，否则 return false
			return currentMatch && isMatchCore(s, sIndex + 1, p, pIndex + 1);
        }
    }



    bool isMatch(string s, string p) {
        return doMatch(s, 0, p, 0);
    }
    bool isMatchCore(string& s, int sb, string& p, int pb){
        if(s[sb]=='\0'&&p[pb]=='\0')
            return true;
        if(s[sb]!='\0'&&p[pb]=='\0')
            return false;
        if(p[pb+1]=='*'){
            if((p[pb]==s[sb]||p[pb]=='.') && s[sb]!='\0')
                return isMatchCore(s,sb+1,p,pb+2) || isMatchCore(s,sb+1,p,pb) || isMatchCore(s,sb,p,pb+2);
            else
                return isMatchCore(s,sb,p,pb+2);
        }
        if((p[pb]==s[sb]||(p[pb]=='.')&&s[sb]!='\0'))
            return isMatchCore(s,sb+1,p,pb+1);
        return false;
    }
    // 执行用时 :2680 ms, 在所有 C++ 提交中击败了5.00% 的用户
    // 内存消耗 :7.9 MB, 在所有 C++ 提交中击败了100.00%的用户
};
```