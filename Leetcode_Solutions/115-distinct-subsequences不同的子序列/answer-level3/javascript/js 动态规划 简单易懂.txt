
### [115\. 不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)

Difficulty: **困难**


给定一个字符串 **S**和一个字符串 **T**，计算在 **S** 的子序列中 **T** 出现的个数。

一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，`"ACE"` 是 `"ABCDE"` 的一个子序列，而 `"AEC"` 不是）

**示例 1:**

```
输入: S = "rabbbit", T = "rabbit"
输出: 3
解释:

如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
(上箭头符号 ^ 表示选取的字母)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
```

**示例 2:**

```
输入: S = "babgbag", T = "bag"
输出: 5
解释:

如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。
(上箭头符号 ^ 表示选取的字母)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
```


#### Solution

Language: **JavaScript**

**解题思路：**

S = "babgbag", T = "bag"

|T\S| "" | b  | a | b | g | b | a | g |
|---|---|---|---|---|---|---|---|---|
| ""  | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| b  | 0 | 1 | 1 | 2 | 2 | 3 | 3 | 3 |
| a  | 0 | 0 | 1 | 1 | 1 | 1 | 4 | 4 |
| g  | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 5 |
&nbsp;
1. 定义 `dp table`
   - `dp[i][j]` 表示 `s[0-i]` 的子序列 与 `t[0-j]` 相等的个数
2. 定义 `dp` 方程
   - `if (s[i] !== t[j])`
     - 此时 `dp[i][j]` 等价于 `dp[i - 1][j]`，所以 `dp[i][j] = dp[i - 1][j]`
   - `if (s[i] === t[j])` 那么这时要分为两种情况，选不选 `s[i]` 作为`s[0-i]`子序列的最后一个字符
     - 选，那么 `dp[i][j] = dp[i - 1][j - 1]`
     - 不选，那么 `dp[i][j] = dp[i - 1][j]`
     - 综上，`dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]`
3. `dp table` 初始化
   - 在 `s`、`t` 字符串的前面加上一个空字符串，将 `dp` 初始化成 `s.length + 1` `*` `t.length + 1` 的二维数组，并将所有的值全部初始化为 `0`
   - 当 `j = 0` 时，`t` 为空字符串，则 `dp[i][0] = 1`
4. 结果
   - `return dp[s.length][t.length]`

**代码**

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var numDistinct = function(s, t) {
    let dp = Array.from({length: s.length + 1}, _ => Array(t.length + 1).fill(0));
    for (let i = 0; i <= s.length; i++) dp[i][0] = 1;
    for (let i = 1; i <= s.length; i++) {
        for (let j = 1; j <= t.length; j++) {
            if (s[i - 1] === t[j - 1]) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j -1]
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[s.length][t.length];
};
```

**时间复杂度：** `O(M * N)`，`M` 为字符串 `s` 的长度，`N` 为字符串 `t` 的长度
**空间复杂度：** `O(M * N)`，`M` 为字符串 `s` 的长度，`N` 为字符串 `t` 的长度

