```java
class Solution {
    // 状态 dp[i][j] : 表示 s 的前 i 个字符和 p 的前 j 个字符是否匹配 (true 的话表示匹配)
    // 状态转移方程：
    //      1. 当 s[i] == p[j]，或者 p[j] == ? 那么 dp[i][j] = dp[i - 1][j - 1];
    //      2. 当 p[j] == * 那么 dp[i][j] = dp[i][j - 1] || dp[i - 1][j]    其中：
    //      dp[i][j - 1] 表示 * 代表的是空字符，例如 ab, ab*
    //      dp[i - 1][j] 表示 * 代表的是非空字符，例如 abcd, ab*
    // 初始化：
    //      1. dp[0][0] 表示什么都没有，其值为 true
    //      2. 第一行 dp[0][j]，换句话说，s 为空，与 p 匹配，所以只要 p 开始为 * 才为 true
    //      3. 第一列 dp[i][0]，当然全部为 false
    public boolean isMatch(String s, String p) {
        int m = s.length();
        int n = p.length();

        // 状态 dp[i][j] : 表示 s 的前 i 个字符和 p 的前 j 个字符是否匹配
        boolean[][] dp = new boolean[m + 1][n + 1];

        // 初始化
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            dp[0][i] = dp[0][i - 1] && p.charAt(i - 1) == '*';
        }

        // 状态转移
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s.charAt(i - 1) == p.charAt(j - 1) || p.charAt(j - 1) == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p.charAt(j - 1) == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        
        // 返回结果
        return dp[m][n];

    }
}
```

对于上面的动态规划的逻辑，**最难理解** 的地方莫过于 `p.charAt(j - 1) = "*"` 的方程的推导了，那么我们结合一个示例来画出填充 dp 数组的过程，我们可以在看这个图画的过程中理解在 `p.charAt(j - 1) = "*"` 的方程推导。

我们以：`s = abcd` 和 `p = "ab*"` 为例，请看下面的轮播图：

<![img](https://pic.leetcode-cn.com/ba0803ad924a2d1aa413f7b03ea3c2489feffa660a39c373e6269d23aef273b8-image.png),![img](https://pic.leetcode-cn.com/1b8558072c2a979185f7d4add259a2d109c8589ff60d098a450721d7792b48a9-image.png),![img](https://pic.leetcode-cn.com/b533bae35560d1045172732ca56289a3428c17caa85236fab6b579f297c7051a-image.png),![img](https://pic.leetcode-cn.com/77723f07426ccd60406077e6396ebbe593bce8885e761492a5a7e44d2d263054-image.png),![img](https://pic.leetcode-cn.com/5511c1b2392a72b6e1b2e03c3991fd5dab5d7ae6cdca7f5f568ecfef49bc0c21-image.png),![img](https://pic.leetcode-cn.com/b9d282e938743047cb6e240767f882cefe9e2ec26679a7be6d110cfcb2186c13-image.png),![img](https://pic.leetcode-cn.com/6b9cf43354c9209a524a79faaae54816a4b347858901502d44c85aada834138d-image.png),![img](https://pic.leetcode-cn.com/598ffaab5f88cfa8830f5a528fedfa60848c6fcf3d19d662b485920e8547396e-image.png),![img](https://pic.leetcode-cn.com/4323eed32f58441cdc12d0a1ed4fc268dbc7225bec7e89b3ccd0ac1892d8aa47-image.png),![img](https://pic.leetcode-cn.com/5410600de7c61ca04860f060e577798923d92ed5ade1d7d99e89bb88d1fe5c7d-image.png),![img](https://pic.leetcode-cn.com/02e8010e25bd3913d99491287a51f60ca9f9f0d39e67e332d094d898bfeb61a3-image.png),![img](https://pic.leetcode-cn.com/6eafbda68e5a51111fb11f1cc3afdff0f6965413283b7bffc6e5d1df0f7cc9ea-image.png),![img](https://pic.leetcode-cn.com/8703fe3c91bad27af55a75b0d08bda55a2b3819f159efadb5d52451ff8d9b421-image.png),![img](https://pic.leetcode-cn.com/62641e9eee89559f7c57705980f36b445a9e4bf5c5c290774e3a2ead9561f801-image.png)>














