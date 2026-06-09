问题的关键是'\*'的处理。如果没有'\*'，一个个比对就行了；而如果有'\*'，不但会影响后续字符的匹配，还会影响上一个字符的匹配（可能匹配零个）。

为此，在一个个比对的过程中，先检查p的下一个字符是否是'\*'，如果不是，好办；如果是，分为两种情况：
1. p的当前字符为'.'，则p的下下个字符可能跟s的当前字符匹配，也可能跟s后续的某个字符匹配，其间跳过的字符可以是任何字母。
1. p的当前字符为字母，则p的下下个字符可能跟s的当前字符匹配，也可能跟s后续的某个字符匹配，但其间跳过的字符必须与p的当前字符匹配。

由于不知道其间跳过了多少字符（或者说'\*'匹配多少字符），这里采用的是递归加循环的方法。递归函数返回后续所有字符是否匹配，循环则是从s的当前字符开始一个个去试，看后续所有字符是否匹配成功。字符串最终匹配成功的标志是：s和p比对到最后，同时到达各自的末尾。

```
class Solution {
public:
    // check whether substring of s from sIndex matches substring of p from pIndex
    // sIndex==s.size() or pIndex==p.size() means that the check goes to end
    bool isMatchSubstring(string& s, string& p, int sIndex, int pIndex) {
        while (true) {
            if (sIndex==s.size() && pIndex==p.size())
                return true;
            if (pIndex+1<p.size() && p[pIndex+1]=='*') {
                if (p[pIndex]=='.') {
                    for (int i=sIndex;i<=s.size();i++) {
                        if (isMatchSubstring(s,p,i,pIndex+2))
                            return true;
                    }
                    return false;
                } else {
                    for (int i=sIndex;i<=s.size();i++) {
                        if (isMatchSubstring(s,p,i,pIndex+2))
                            return true;
                        if (s[i]!=p[pIndex])
                            break;
                    }
                    return false;
                }
            }
            if (sIndex==s.size() || pIndex==p.size())
                return false;
            if (p[pIndex]=='.' || s[sIndex]==p[pIndex]) {
                sIndex++;
                pIndex++;
            } else
                return false;
        }
    }

    bool isMatch(string s, string p) {
        return isMatchSubstring(s,p,0,0);
    }
};
```
