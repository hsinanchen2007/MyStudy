### 动态规划

很容易想到状态定义为: f[i][j] 表示最少需要几次能打印出 s 的 [i, j] 区间的子串. 而一个状态的决策就是我们在 [i, j] 这段区间内, 选择哪一段子区间打印哪一个字符

不过进一步想: 这段区间的第一个字符 s[i] 迟早要被正确打印, 所以决策可以改成打印多少个 s[i]
即枚举 k, 我们在 [i, k] 的范围内打印 s[i], 然后转移到子问题.

再进一步, 参考 LeetCode 官方题解的巧妙写法:

```
f[i][j] = f[i+1][j] + 1  (单独打印 s[i])
f[i][j] = min{ f[i][k-1] + f[k+1][j] }  i < k <= j 且 s[i] == s[k]
```

可以这么理解这个写法: 当 s[i] == s[k] 时, 我们令 k 的字符与 i 的字符在同一次打印, 所以打印 [i, k] 需要的次数就等价于打印 [i, k-1], 就是子问题 f[i][k-1], 再加上剩下的 f[k+1][j], 就构成了这个状态转移方程

使用记忆化搜索实现

### 代码

```java
/**
 * 动态规划
 * 很容易想到状态定义为: f[i][j] 表示最少需要几次能打印出 s 的 [i, j] 区间的子串
 * 而一个状态的决策就是我们在 [i, j] 这段区间内, 选择哪一段子区间打印哪一个字符
 * 不过进一步想: 这段区间的第一个字符 s[i] 迟早要被正确打印, 所以决策可以改成打印多少个 s[i]
 * 即枚举 k, 我们在 [i, k] 的范围内打印 s[i], 然后转移到子问题
 * <p>
 * 再进一步, 参考 LeetCode 官方题解的巧妙写法:
 * f[i][j] = f[i+1][j] + 1  (单独打印 s[i])
 * f[i][j] = min{ f[i][k-1] + f[k+1][j] }  i < k <= j 且 s[i] == s[k]
 * 可以这么理解这个写法: 当 s[i] == s[k] 时, 我们令 k 的字符与 i 的字符在同一次打印,
 * 所以打印 [i, k] 需要的次数就等价于打印 [i, k-1], 就是子问题 f[i][k-1]
 * 再加上剩下的 f[k+1][j], 就构成了这个状态转移方程
 * 使用记忆化搜索实现
 */
class Solution {
    private int[][] f;
    private String s;

    private int dp(int i, int j) {
        if (i > j || f[i][j] > 0) {
            return i > j ? 0 : f[i][j];
        }
        f[i][j] = dp(i + 1, j) + 1;
        char c = s.charAt(i);
        for (int k = i + 1; k <= j; k++) {
            if (c == s.charAt(k)) {
                f[i][j] = Math.min(f[i][j], dp(i, k - 1) + dp(k + 1, j));
            }
        }
        return f[i][j];
    }

    public int strangePrinter(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int n = s.length();
        f = new int[n][n];
        this.s = s;
        return dp(0, n - 1);
    }
}
```