### 解题思路
多个\*连起来和单个\*是一样的效果，直接合并

模式串边界值：
"","\*","a\*b\*"，对应dp[0][x]=true

再对模式串分情况讨论

### 代码

```cpp
class Solution {
public:
    bool **dp;
    bool isMatch(string s, string p) {
        if (p.length()==0 && s.length()==0) return true;
        if (p.length()==0) return false;
        //合并*
        string t = "";
        t+=p[0];
        for (int i=1;i<p.length();i++) {
            if (p[i]=='*' && t[t.length()-1]=='*') continue;
            else {
                t+=p[i];
            }
        }
        //dp[i][j] s的前i个和t的前j个是否匹配
        dp = new bool *[s.length()+1];
        for (int i=0;i<s.length()+1;i++) dp[i] = new bool[t.length()+1]{false};
        dp[0][0] = true;
        int idx = 1;
        //匹配空串
        if(t[0]=='*')  {
            dp[0][1] = true;
            idx++;
        }
        while (idx<t.length() && t[idx] == '*') {
            dp[0][idx+1] = true;
            idx+=2;
        } 
        char last = '$';//空
        for (int i=1;i<=s.length();i++) {
            for (int j=1;j<=t.length();j++) {
                if (t[j-1] == '*') {
                    if (s[i-1]!=last && last!='.') {
                        if (j==1) dp[i][j] = false;
                        //a!=b*: 不匹配
                        else dp[i][j] = dp[i][j-2];
                    }
                    else {
                        //a=a*类：
                        //匹配一个:ba=ba*,匹配多个:baa=ba*,baaa=ba*,不匹配:b=ba*
                        dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-2];
                    }
                }
                else {
                    if (t[j-1]=='.' || t[j-1]==s[i-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else {
                        dp[i][j] = false;
                    }
                    last = t[j-1];
                }
            }
        }
        return dp[s.length()][t.length()];
        
    }
};
```

### 复杂度
合并"\*":O(n)

匹配空串:O(n)

动态规划:O(mn)

执行用时 :8 ms, 在所有 C++ 提交中击败了93.22%的用户

内存消耗 :9 MB, 在所有 C++ 提交中击败了100.00%的用户