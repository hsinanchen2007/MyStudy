### 解题思路
动态规划，这个时候一定要定义好dp数组的含义，我们定义dp[i][j]为字符串s中前i个字符和字符串p中前j个字符是否能匹配上，根据p中可能出现的字符情况，有以下三种情况：
1. 如果`p[j] == s[i]`, 那么dp[i][j] = dp[i-1][j-1],意思就是说，如果p的第j个字符和s的第i个字符匹配上了，那么dp[i][j]是否为true取决于dp[i-1][j-1]
2. 如果p[j] == '.',那么p[j]此时就可以匹配任意字符，情况就和1一样了，dp[i][j] = dp[i-1][j-1]
3. 如果p[j] == '*',那么此时又要分3中情况：
    1. 如果p[j-1] != '.' and p[j-1] != s[i],也就说*之前的字符不能和当前字符s[i]匹配上，那么这个时候我们也不直接将dp[i][j]设置为false，而是将此时的 `*` 看作个数为0，查看dp[i][j-2]的状态，即j的前2位的状况.此时dp[i][j] = dp[i][j-2]
    2. 否则话，说明p[j-1]能够和s[i]匹配上，那么此时*就会有3个状态，分别当作0个 1个 多个来用，对应的状态就是
        - dp[i][j] = dp[i][j-2], *当作0个来用
        - dp[i][j] = dp[i][j-1], *当作1个来用
        - dp[i][j] = dp[i-1][j]，*当作多个来用

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if s == None and p == None:
            return True
        
        n = len(s)
        m = len(p)
        dp = [[False for _ in range(m+1)] for _ in range(n+1)]
        dp[0][0] = True
        for j in range(m):
            if p[j] == '*' and dp[0][j-1]:
                dp[0][j+1] = True
        for i in range(0, n):
            for j in range(0, m):
                if p[j] == '.' or p[j] == s[i]:
                    dp[i+1][j+1] = dp[i][j]
                elif p[j] == '*':
                    if p[j-1] != s[i] and p[j-1] != '.':
                        dp[i+1][j+1] = dp[i+1][j-1] # 相当于*为0个元素
                    else:
                        dp[i+1][j+1] = dp[i+1][j-1] or dp[i+1][j] or dp[i][j+1]
                            # *为0个
                                    # *为1个
                                            # *为多个

        return dp[n][m]
```