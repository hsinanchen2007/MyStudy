
记`f(i, j)`表示从字符串`s`的下标`i`到`j`的子串是否是回文，是为`true`，否为`false`。
以`babab`为例，知道如果整个字符串为回文，有两个条件：
1、第一个字符跟最后一个字符一定为回文；
2、去掉第一个和最后一个字符，中间的字符为回文，即`aba`为回文。
由此得出动态规划方程为：
`f(i, j) = f(i+1, j-1) and si == sj`

代码如下：

```
    public String longestPalindrome(String s) {
        int n = s.length();
        if (n < 2) {
            return s;
        }
        String longestStr = "";
        // 定义一个是否是回文的二维数组
        boolean[][] f = new boolean[n + 1][n + 1];
        // 长度为1的一定是回文，这里只记录最后一个子串
        for (int i = 0; i < n; i++) {
            f[i][i] = true;
            longestStr = s.substring(i, i + 1);
        }
        // 长度为2的两个字符必须相同，这里只记录最后两个字符
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                f[i][i + 1] = true;
                longestStr = s.substring(i, i + 2);
            }
        }
        // 长度大于3，由方程式f(i, j) = f(i+1, j-1) and si == sj判断即可
        for (int j = 2; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (f[i + 1][j - 1] && s.charAt(i) == s.charAt(j)) {
                    f[i][j] = true;
                    if (j - i + 1 > longestStr.length()) {
                        longestStr = s.substring(i, j + 1);
                    }
                }
            }
        }
        return longestStr;
    }
```
