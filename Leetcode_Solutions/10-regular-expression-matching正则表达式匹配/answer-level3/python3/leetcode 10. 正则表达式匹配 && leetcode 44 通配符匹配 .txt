# [leetcode 10. 正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/)
## 题意：
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素

所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

## 思路：
这个匹配的过程实际上就是一个回溯的搜索（暴力), 如果是这个思路，难点就是这个写法，然后注意这个过程具有```子结构```的特点，所以可以用记忆化搜索来写。

先看第一种回溯思路写法，实际看成一个自上而下的搜索，理清楚几个搜索条件的分界点：
- 当字符规律p为空时，s必须为空。
- 接着判断当p[1] == '*'时候，有两个不同回溯方向，一个可以考虑当前当前匹配零个，一个考虑p[0]匹配到当前s[0]。
- 如果p[1]!='*',那只有考虑p[0]匹配掉当前s[0]。

最初我的（丑陋）的写法：
```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p: return not s
        if len(p) >=2 and p[1] == '*':
            return self.isMatch(s, p[2:]) or (len(s)>0 and (p[0] == s[0] or p[0] =='.')) and self.isMatch(s[1:], p)
        elif len(s)>0 and (p[0] == s[0] or p[0] =='.'):
            return self.isMatch(s[1:], p[1:])
        else : return False

```
看了官方题解python（优美）写法：
```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p: return not s
        first_match = bool(s) and p[0] in {s[0], '.'}
        if len(p) >=2 and p[1] == '*':
            return self.isMatch(s, p[2:]) or first_match and self.isMatch(s[1:], p)
        else :
            return first_match and self.isMatch(s[1:], p[1:])
```
这种不带记忆化操作的写法时间是```1464 ms```。

回溯写法 C++
```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() ==0) return s.size() == 0 ;
        bool first_match = s.size()>0 && (p[0] == s[0]||p[0] == '.');
        if(p.size()>=2&&p[1]=='*'){
             return (isMatch(s,p.substr(2)) || first_match && isMatch(s.substr(1), p));
        }
        else return first_match && isMatch(s.substr(1), p.substr(1));
    }
};
```
c++不带记忆化操作时限是```416 ms```。

根据上面分析，这题回溯的过程具有子结构的特点，我们可以用一个数组保存每一次回溯搜索状态的值，俗称记忆化操作。

这里用```dp(i,j)```表示 s[i:]与 p[j:]匹配的情况，则可以将回溯自上而下搜索的过程加入保存每个状态的操作：
```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memo = {}
        def dp(i, j):
            if (i,j) not in memo:
                if j == len(p):
                    ans = True if i == len(s) else False
                else :
                    first_match = i< len(s) and p[j] in {s[i], '.'}
                    if j+1 < len(p) and p[j+1] == '*':
                        ans =  dp(i,j+2) or first_match and dp(i+1,j)
                    else :
                        ans =  first_match and dp(i+1, j+1)
                memo[i,j] = ans
            return memo[i, j]
        return dp(0,0)

```

这种写法时间复杂度是```O(len(s)* len(p))```, 时限是```40ms```,超过97.08%的用户。

回溯实际上看成自上朝下的搜索方式，这题又有**子结构**的特点，设定好状态表示```dp（i，j)```后，我们自然可以考虑它状态转移方程，写成一种自下朝上的搜索过程,也可以说是**动态规划**的思想。

这里的dp(i,j)仍然表示 s[i:]和p[j:]是否匹配。
```python

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
       n, m  = len(s), len(p)
       print(n,m)
       dp = [[False] * (m+1) for _ in range(n+1)]
       print(dp)
       dp[n][m] = True
       for i in range(n,-1,-1):
           for j in range(m-1, -1,-1):
               first_match = i<n and p[j] in {s[i], '.'}
               if j+1 < m and p[j+1] =='*':
                   dp[i][j] = dp[i][j+2] or first_match and dp[i+1][j]
               else :
                   dp[i][j] = first_match and dp[i+1][j+1]
       return dp[0][0]
```

如果dp(i,j)表示s[:i]和p[:j]是否匹配,则转移方程以及写法都需要改变:

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
       n, m  = len(s), len(p)
       print(n,m)
       dp = [[False] * (m+1) for _ in range(n+1)]
       dp[0][0] = True
       for i in range(0, n+1 ,1):
           for j in range(1, m+1 ,1):
               first_match = i>0 and p[j-1] in {s[i-1], '.'}
               if j>=2 and p[j-1] =='*':
                   dp[i][j] = dp[i][j-2] or  (i>0 and p[j-2] in {s[i-1],'.'}) and dp[i-1][j]
               else :
                   dp[i][j] = first_match and dp[i-1][j-1]
       #print(dp)
       return dp[n][m]
```

### leetcode 44 
这道题就相当于是leetcode10简化版，‘？’作用和'.'一样，不同是'*'可以匹配任意字符串。

所以只需要在leetcode10代码基础上把状态转移的条件修改一下：

自底向下：
```py
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memo = {}
        def dp(i, j):
            if (i,j) not in memo:
                if j == len(p):
                    ans = True if i == len(s) else False
                else :
                    first_match = i< len(s) and p[j] in {s[i], '?', '*'}
                    if p[j] == '*':
                        ans =  dp(i,j+1) or first_match and dp(i+1,j)
                    else :
                        ans =  first_match and dp(i+1, j+1)
                memo[i,j] = ans
            return memo[i, j]
        return dp(0,0)
```

自底向上：
```py
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [[False]* (n+1) for _ in range(m+1)]
        dp[m][n] = True
        for i in range(m, -1,-1):
            for j in range(n-1, -1,-1):
                first_match = i < m and p[j] in (s[i], '?')
                if p[j] == '*':
                    dp[i][j] = dp[i][j+1] or i<m and dp[i+1][j]
                else:
                    dp[i][j] = first_match and dp[i+1][j+1]
        return dp[0][0]
```

