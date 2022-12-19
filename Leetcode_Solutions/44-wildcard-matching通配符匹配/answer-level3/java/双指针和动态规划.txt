## 思路:

**思路一:** 利用两个指针进行遍历。

在代码里解释.

时间复杂度为:$O(mn)$

**思路二:** 动态规划

自底向上

`dp[i][j]`表示`s`到`i位置`,`p`到`j`位置是否匹配!

初始化:

1. `dp[0][0]`:什么都没有,所以为`true`
2. 第一行`dp[0][j]`,换句话说,`s`为空,与`p`匹配,所以只要`p`开始为`*`才为`true`
3. 第一列`dp[i][0]`,当然全部为`False`

动态方程:

1. 如果`(s[i] == p[j]  || p[j] == "?")  && dp[i-1][j-1]` ,有`dp[i][j] = true`

2. 如果`p[j] == "*" && (dp[i-1][j] = true || dp[i][j-1] = true) `有`dp[i][j] = true`

   ​	note:

   ​		 `dp[i][j-1]`,表示`*`代表是空字符,例如`ab,ab*`

   ​		`dp[i-1][j]`,表示`*`代表非空任何字符,例如`abcd,ab*`
自顶向下就很简单了!

   



​	

## 代码:

思路一

```python [1]
class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        i = 0
        j = 0
        start = -1
        match = 0
        while i < len(s):
            # 一对一匹配,匹配成功一起移
            if j < len(p) and (s[i] == p[j] or p[j] == "?"):
                i += 1
                j += 1
            # 记录p的"*"的位置,还有s的位置
            elif j < len(p) and p[j] == "*":
                start = j
                match = i
                j += 1
            # j 回到 记录的下一个位置
            # match 更新下一个位置
            # 这不代表用*匹配一个字符
            elif start != -1:
                j = start + 1
                match += 1
                i = match
            else:
                return False
         # 将多余的 * 直接匹配空串
        return all(x == "*" for x in p[j:])
```



```java [1]
class Solution {
    public boolean isMatch(String s, String p) {
        int sn = s.length();
        int pn = p.length();
        int i = 0;
        int j = 0;
        int start = -1;
        int match = 0;
        while (i < sn) {
            if (j < pn && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?')) {
                i++;
                j++;
            } else if (j < pn && p.charAt(j) == '*') {
                start = j;
                match = i;
                j++;
            } else if (start != -1) {
                j = start + 1;
                match++;
                i = match;
            } else {
                return false;
            }
        }
        while (j < pn) {
            if (p.charAt(j) != '*') return false;
            j++;
        }
        return true;
        
    }
}
```




思路2


```python [2]
class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        sn = len(s)
        pn = len(p)
        dp = [[False] * (pn + 1) for _ in range(sn + 1)]
        dp[0][0] = True
        for j in range(1, pn + 1):
            if p[j - 1] == "*":
                dp[0][j] = dp[0][j - 1]

        for i in range(1, sn + 1):
            for j in range(1, pn + 1):
                if (s[i - 1] == p[j - 1] or p[j - 1] == "?"):
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == "*":
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1]
        return dp[-1][-1]
```

```java [2]
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        dp[0][0] = true;
        for (int j = 1; j < p.length() + 1; j++) {
            if (p.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = 1; j < p.length() + 1; j++) {
                if (s.charAt(i - 1) == p.charAt(j - 1) || p.charAt(j - 1) == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p.charAt(j - 1) == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[s.length()][p.length()];
        
    }
}
```
自顶向下
```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        import functools

        @functools.lru_cache(None)
        def dfs(i, j):
            if j == len(p): return i == len(s)
            if i < len(s) and s[i] == p[j] and dfs(i + 1, j + 1):
                return True
            if i < len(s) and p[j] == "?" and dfs(i + 1, j + 1): return True
            if p[j] == "*":
                # * 依次表示多个, 一个, 零个字符
                if (i < len(s) and (dfs(i + 1, j) or dfs(i + 1, j + 1))) or dfs(i, j + 1) : return True
            return False
        
        return dfs(0, 0)
```

