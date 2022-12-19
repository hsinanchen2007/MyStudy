### 解题思路
每次判断模式串前两字符，
带*的循环匹配校验串前n个符合条件的(n >= 0)
不带的直接比较首字符
18ms
看了官解加了dp
2ms
### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {

        if ("".equals(p))
            return "".equals(s);

        return matchTask(s.toCharArray(), p.toCharArray(), 0, 0, new Boolean[s.length() + 1][p.length() + 1]);

    }

    // DFS + dp
    public static boolean matchTask(char[] s, char[] p, int i, int j, Boolean[][] dp) {
        if (i > s.length)
            return false;
        if (dp[i][j] != null)
            return dp[i][j];

        if (j == p.length) {
            return dp[i][j] = i == s.length;
        }
        
        boolean save = false;
        if (j + 1 < p.length && p[j + 1] == '*') {
            // 0个符合的处理
            if (matchTask(s, p, i, j + 2, dp))
                save = true;
            else if (p[j] == '.') {
                for (int k = i + 1; k <= s.length; k++) {
                    if (matchTask(s, p, k, j + 2, dp)) {
                        save = true;
                        break;
                    }
                }
            } else {
                for (int k = i + 1; k <= s.length && s[k - 1] == p[j]; k++) {
                    if (matchTask(s, p, k, j + 2, dp)) {
                        save = true;
                        break;
                    }
                }
            }
        } else {
            if (p[j] == '.' || (i < s.length && p[j] == s[i]))
                save = matchTask(s, p, i + 1, j + 1, dp);
        }

        dp[i][j] = save;
        return save;
    }

}
```