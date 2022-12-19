>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：递归

递归的终止条件：

（1）如果s字符串的长度为0，如果此时字符串p当且仅当有形如"a\*b\*c\*d\*e\*"这样的格式时，返回true；否则，返回false。

（2）如果s字符串的长度不为0，而p字符串的长度为0，返回false。

递归的过程：

（1）如果s的最后一个字符与p的最后一个字符相等，或者说p的最后一个字符为"."，那么我们直接看字符串s中除去最后一个字符的字符串能否与字符串p中除去最后一个字符的字符串相匹配。

（2）如果p的最后一个字符为"*"，这种情况比较复杂，又分为两种情况。

    a.如果s的最后一个字符既不与p的最后第二个字符相等，p的最后第二个字符也不为"."，那么我们直接看字符串s能否与字符串p中除去最后两个字符的字符串相匹配。

    b.如果s的最后一个字符与p的最后第二个字符相等，或者说p的最后第二个字符为"."，，这种情况比较复杂，又分为三种情况。

        b-1：我们看字符串s中除去最后一个字符的字符串能否与字符串p相匹配（即把s中的最后一个字符与p的最后一个字符（*）相匹配）。

        b-2：我们看字符串s能否与字符串p中除去最后一个字符的字符串相匹配（即把s中的最后一个字符与p的最后第二个字符相匹配）。

        b-3：我们看字符串s中除去最后一个字符的字符串能否与字符串p中除去最后两个字符的字符串相匹配（直接舍去p中的最后两个字符）。

只要上述b-1、b-2、b-3三种情况中有一种情况相匹配，我们就返回true。如果三种情况都不匹配，我们就返回false。

执行用时：312ms，击败8.95%。消耗内存：111.6MB，击败5.03%。

```java
public class Solution {
    public boolean isMatch(String s, String p) {
        int ns = s.length(), np = p.length();
        if (ns == 0 && np == 0) {
            return true;
        }
        if (ns != 0 && np == 0) {
            return false;
        }
        if (ns == 0) {
            if ((np & 1) == 1) {
                return false;
            }
            int i = 1;
            while (i < p.length() && p.charAt(i) == '*') {
                i += 2;
            }
            return i == p.length() + 1;
        }
        if (s.charAt(ns - 1) == p.charAt(np - 1) || p.charAt(np - 1) == '.') {
            return isMatch(s.substring(0, ns - 1), p.substring(0, np - 1));
        }
        if (p.charAt(np - 1) == '*') {
            if (s.charAt(ns - 1) != p.charAt(np - 2) && p.charAt(np - 2) != '.') {
                return isMatch(s, p.substring(0, np - 2));
            }
            return isMatch(s.substring(0, ns - 1), p) || isMatch(s, p.substring(0, np - 1))
                    || isMatch(s, p.substring(0, np - 2));
        }
        return false;
    }
}
```

# 解法二：动态规划

用题给的示例4来模拟递归的过程如下图所示：

![image.png](https://pic.leetcode-cn.com/7e4eed4d8274551648127a99ac06eed1551dbcdc6fd3d18b3f92485dc92a6fe8-image.png)

图中紫色椭圆所在区域就是递归过程中出现的重叠子问题，既然发现了重叠子问题，那么肯定就可以用动态规划来解决！而动态规划的关键是状态定义的合适选取以及发现正确的状态转移。

状态定义：

dp[x, y]:字符串s中[0, x - 1]范围内的字符串能否匹配字符串p中[0, y - 1]范围内的字符串

状态转移：

（1）dp[0, 0] = true。

（2）当y == 0时，dp[x, 0] = false, x ∈[1, s.length()]。

（3）当x == 0时，如果p的前缀是a*b*c*这样的格式，那么dp[0, 2] = dp[0, 4] = dp[0, 6] = true。

（4）如果p.charAt(y) == '.'或者p.charAt(y) == s.charAt(x), dp[x, y] = dp[x - 1, y - 1]。

（5）如果p.charAt(y) == '*'，

    a.如果s.charAt(x) == p.charAt(y - 1) 或 p.charAt(y - 1) == '.'，

        a-1：使用'*'号进行匹配：dp[x - 1, y]

        a-2：只使用'*'号前面的那个字符匹配，不使用'*'匹配：dp[x, y - 1]

        a-3：'*'号前面的那个字符在匹配的过程当中一个都不使用：dp[x, y - 2]

    dp[x, y] = dp[x - 1, y] || dp[x, y - 1] || dp[x, y - 2]。

    b.如果s.charAt(x) != p.charAt(y - 1) 且 p.charAt(y - 1) != '.'

    *号前面的那个字符在匹配的过程当中一个都不使用，dp[x, y] = dp[x, y - 2]。

时间复杂度和空间复杂度均是O(mn)，其中m为字符串s的长度，n为字符串p的长度，

执行用时：8ms，击败87.43%。消耗内存：35.8MB，击败89.46%。

```java
public class Solution {
    public boolean isMatch(String s, String p) {
        int ns = s.length() + 1, np = p.length() + 1;
        boolean[][] dp = new boolean[ns][np];
        dp[0][0] = true;
        for (int i = 1; i < np; i++) {
            if (((i - 1) & 1) == 1) {
                if (p.charAt(i - 1) != '*') {
                    break;
                }
                dp[0][i] = true;
            }
        }
        for (int i = 1; i < ns; i++) {
            for (int j = 1; j < np; j++) {
                if (p.charAt(j - 1) == '.' || p.charAt(j - 1) == s.charAt(i - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (p.charAt(j - 1) == '*') {
                    if (s.charAt(i - 1) != p.charAt(j - 2) && p.charAt(j - 2) != '.') {
                        dp[i][j] = dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                    }
                }
            }
        }
        return dp[ns - 1][np - 1];
    }
}
```



