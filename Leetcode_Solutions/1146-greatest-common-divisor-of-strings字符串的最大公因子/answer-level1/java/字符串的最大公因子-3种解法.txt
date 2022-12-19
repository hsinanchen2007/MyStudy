>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(max(n1, n2) * σ(gcd(n1, n2)))，其中n1为字符串str1的长度，n2为字符串str2的长度，gcd(n1, n2)为n1和n2的最大公约数，σ(gcd(n1, n2))为n1和n2的最大公约数的约数个数。空间复杂度是O(n1 + n2)。

执行用时：1ms，击败93.63%。消耗内存：38.3MB，击败12.00%。

```java
public class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int n1 = str1.length(), n2 = str2.length();
        for (int i = Math.max(n1, n2); i >= 1; i--) {
            if (n1 % i == 0 && n2 % i == 0) {
                String tmp = str1.substring(0, i);
                if (check(str1, tmp) && check(str2, tmp)) {
                    return tmp;
                }
            }
        }
        return "";
    }

    private boolean check(String str, String tmp) {
        StringBuilder sb = new StringBuilder();
        while (sb.length() < str.length()) {
            sb.append(tmp);
        }
        return str.equals(sb.toString());
    }
}
```

# 解法二：解法一的改进

如果存在一个符合要求的字符串X，那么也一定存在一个符合要求的字符串X'，它的长度为str1和str2长度的最大公约数。

时间复杂度和空间复杂度均是O(n1 + n2)，其中n1为字符串str1的长度，n2为字符串str2的长度。

执行用时：1ms，击败93.63%。消耗内存：38.7MB，击败8.80%。

```java
public class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int gcd = gcd(str1.length(), str2.length());
        String tmp = str1.substring(0, gcd);
        if (check(str1, tmp) && check(str2, tmp)) {
            return tmp;
        }
        return "";
    }

    private boolean check(String str, String tmp) {
        StringBuilder sb = new StringBuilder();
        while (sb.length() < str.length()) {
            sb.append(tmp);
        }
        return str.equals(sb.toString());
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
```

# 解法三：找规律

字符串str1和字符串str2存在最大公因子的充要条件是(str1 + str2).equals(str2 + str1)。

当确定有解的情况下，最优解是长度为gcd(n1, n2)的字符串，其中n1为字符串str1的长度，n2为字符串str2的长度。

时间复杂度和空间复杂度均是O(n1 + n2)。

执行用时：1ms，击败95.96%。消耗内存：42.8MB，击败5.26%。

```java
public class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        return str1.substring(0, gcd(str1.length(), str2.length()));
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
```