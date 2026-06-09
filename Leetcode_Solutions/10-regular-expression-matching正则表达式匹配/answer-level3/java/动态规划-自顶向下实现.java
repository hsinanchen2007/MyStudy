对于dp题目我比较喜欢自顶向下实现，这样比较容易理解。
定义函数isMatch(String s, int len1,
               String p, int len2)

case1: 如果s[len1-1] == p[len2-1]或者他俩不匹配，但是p[len2-1]是'.'，那么该字符就匹配，我们可以继续搜索isMatch(s, len1-1,p, len2-1)。

case2: 如果case1不成立，且p[len2-1]是'*'，那么我们就贪婪匹配，试探'*'能重复多少个*前面的前导符，以替代目标串s的后len个字符。
```
    char preceding = p.charAt(len2 - 2); // 取到*的前导符
    ans = isMatch(s, len1, p, len2 - 2); // 尝试重复0次前导符
    // 尝试1次到len1次前导符，替代s的后len个字符
    for (int len = 1; len <= len1 && (preceding == '.' || s.charAt(len1 - len) == preceding); len++) {
        ans |= isMatch(s, len1 - len, p, len2 - 2);
    }
```

全部代码：
```
class Solution {
    private Boolean[][] memo;

    public boolean isMatch(String s, String p) {
        int n1 = s.length(), n2 = p.length();
        memo = new Boolean[n1 + 1][n2 + 1];
        return isMatch(s, n1, p, n2);
    }

    private boolean isMatch(String s, int len1,
                            String p, int len2) {
        if (len2 == 0) return len1 == 0;
        if (memo[len1][len2] != null) return memo[len1][len2];
        boolean ans = false;
        if (len1 > 0 && (s.charAt(len1 - 1) == p.charAt(len2 - 1) || p.charAt(len2 - 1) == '.')) {
            ans = isMatch(s, len1 - 1, p, len2 - 1);
        } else if (p.charAt(len2 - 1) == '*') {
            char preceding = p.charAt(len2 - 2);
            ans = isMatch(s, len1, p, len2 - 2);
            for (int len = 1; len <= len1 && (preceding == '.' || s.charAt(len1 - len) == preceding); len++) {
                ans |= isMatch(s, len1 - len, p, len2 - 2);
            }
        }
        return memo[len1][len2] = ans;
    }
}
```
