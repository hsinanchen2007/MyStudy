### 动态规划

时间复杂度 $o(n)$, 空间复杂度 $o(1)$ 的动态规划解法.

不过注意, 如果要用三个变量代替 `f` 数组做空间优化, 那么可能会有一些细节问题. (比如变量的初值, 以及特判 `s[0]` 是否 `'0'`)

### 代码

```java
/**
 * 动态规划
 * 定义状态: f[i] 表示 s 的前 i 个字符有多少种解码方式
 * 状态转移: f[i] = SUM f[j] (s[j+1:i]对应一种编码)
 * 初始状态: f[0] = 1, f[1] = 1/0 (str[0] == '0' ? 0 : 1)
 * 最终答案: f[n]
 * 空间优化: f[i] 最多为 f[i-1] + f[i-2], 所以只需要三个变量
 */
class Solution {
    public int numDecodings(String s) {
        if (s == null || s.length() == 0 || s.charAt(0) == '0') {
            return 0;
        }
        char[] str = s.toCharArray();
        int n = str.length;
        int f = 1, f_1 = str[0] == '0' ? 0 : 1, f_2 = 1;  // 最开始 f_1 表示 f[1], f_2 表示 f[0]; f = 1 以防 n == 1 的特殊情况, 而这么做又需要考虑 str[0] == '0', 在最开始判断
        for (int i = 2; i <= n; i++) {
            int n1 = str[i - 1] - '0';  // str: 0-indexed
            int n2 = n1 + (str[i - 2] - '0') * 10;
            f = f_1 * inRange(n1, 1, 10) + f_2 * inRange(n2, 10, 27);
            f_2 = f_1;
            f_1 = f;
        }
        return f;
    }

    private int inRange(int n, int min, int max) {
        return min <= n && n < max ? 1 : 0;
    }
}
```