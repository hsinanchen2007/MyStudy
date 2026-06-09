#### 方法一：动态规划

我们用 `dp[i][j]` 表示字符串 `s1[i:]` 和 `s2[j:]`（`s1[i:]` 表示字符串 `s1` 从第 $i$ 位到末尾的子串，`s2[j:]` 表示字符串 `s2` 从第 $j$ 位到末尾的子串，字符串下标从 0 开始）达到相等所需删除的字符的 ASCII 值的最小和，最终的答案为 `dp[0][0]`。

当 `s1[i:]` 和 `s2[j:]` 中的某一个字符串为空时，`dp[i][j]` 的值即为另一个非空字符串的所有字符的 ASCII 值之和。例如当 `s2[j:]` 为空时，此时有 `j = s2.length()`，状态转移方程为

    dp[i][j] = s1.asciiSumFromPos(i)

也可以写成递推的形式，即

    dp[i][j] = dp[i + 1][j] + s1.asciiAtPos(i)

对于其余的情况，即两个字符串都非空时，如果有 `s1[i] == s2[j]`，那么当前位置的两个字符相同，它们不需要被删除，状态转移方程为

    dp[i][j] = dp[i + 1][j + 1]

如果 `s1[i] != s2[j]`，那么我们至少要删除 `s1[i]` 和 `s2[j]` 两个字符中的一个，因此状态转移方程为

    dp[i][j] = min(dp[i + 1][j] + s1.asciiAtPos(i), dp[i][j + 1] + s2.asciiAtPos(j))

```Python [sol1]
class Solution(object):
    def minimumDeleteSum(self, s1, s2):
        dp = [[0] * (len(s2) + 1) for _ in xrange(len(s1) + 1)]

        for i in xrange(len(s1) - 1, -1, -1):
            dp[i][len(s2)] = dp[i+1][len(s2)] + ord(s1[i])
        for j in xrange(len(s2) - 1, -1, -1):
            dp[len(s1)][j] = dp[len(s1)][j+1] + ord(s2[j])

        for i in xrange(len(s1) - 1, -1, -1):
            for j in xrange(len(s2) - 1, -1, -1):
                if s1[i] == s2[j]:
                    dp[i][j] = dp[i+1][j+1]
                else:
                    dp[i][j] = min(dp[i+1][j] + ord(s1[i]),
                                   dp[i][j+1] + ord(s2[j]))

        return dp[0][0]
```

```Java [sol1]
class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int[][] dp = new int[s1.length() + 1][s2.length() + 1];

        for (int i = s1.length() - 1; i >= 0; i--) {
            dp[i][s2.length()] = dp[i+1][s2.length()] + s1.codePointAt(i);
        }
        for (int j = s2.length() - 1; j >= 0; j--) {
            dp[s1.length()][j] = dp[s1.length()][j+1] + s2.codePointAt(j);
        }
        for (int i = s1.length() - 1; i >= 0; i--) {
            for (int j = s2.length() - 1; j >= 0; j--) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = Math.min(dp[i+1][j] + s1.codePointAt(i),
                                        dp[i][j+1] + s2.codePointAt(j));
                }
            }
        }
        return dp[0][0];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(|S_1|* |S_2|)$。动态规划中用到了两重循环，它们的时间复杂度分别为 $O(|S_1|)$ 和 $O(|S_2|)$，因此总的时间复杂度为 $O(|S_1|* |S_2|)$。
* 空间复杂度：$O(|S_1|* |S_2|)$。动态规划中用到的 `dp` 为 $|S_1| * |S_2|$ 的二维数组。