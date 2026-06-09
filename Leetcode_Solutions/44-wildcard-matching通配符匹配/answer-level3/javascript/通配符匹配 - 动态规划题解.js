### 思路
本题与 [10 Regular Expression Matching](https://leetcode-cn.com/problems/regular-expression-matching) 非常相似，解题的思路也是类似。可以参考之前的[题解](https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-hui-su-ji-dong-tai-gui/)。

依旧是使用动态规划来解题。

#### 状态
我们定义一个二维数组`dp`记录状态，`dp[i][j]`代表`s`的前`i`个字符能否被`p`的前`j`个字符匹配。我们在循环中根据前面的状态逐一得出后续的状态。
#### 转移方程
在假设已知`dp[i][j]`之前的状态，而且已知`s[i]`,`p[j]`的情况下，`dp[i][j]`的状态由以下的情形决定:

* `p[j]`等于`*`，因为`*`可以匹配任意字符，也可为空，即不匹配字符，所以有两种情况:
    * 当`p[j]`不匹配`s[i]`，此时`dp[i][j] = dp[i][j - 1]`,即只需考虑`s`的前`i`个字符能否被`p`的前`j - 1`个字符匹配。
    * 当`p[j]`匹配了`s[i]`，此时`dp[i][j] = dp[i - 1][j]`，即只需考虑`s`的前`i - 1`个字符能否被`p`的前`j`个字符匹配。
* `p[j]`不等于`*`，只需考虑`p[j]`与`s[i]`是否匹配，若匹配则`dp[i][j] = dp[i - 1][j - 1]`。
写成代码:
```JavaScript
if (p[j] === '*') {
    dp[i][j] = dp[i][j - 1] || (i > 0 && dp[i - 1][j]);
} else {
    const match = i > 0 && (p[j] === s[i] || p[j] === '?');
    dp[i][j] = match && dp[i - 1][j - 1];
}
```
#### 初始化
为了方便处理`i - 1`, `j - 1`的情况，我们可以在初始化时在`s`、`p`前添加一位空格，并且设`dp[0][0] = true`。
```JavaScript
s = ' ' + s;
p = ' ' + p;
const dp = [...new Array(s.length)].map(() => [...new Array(p.length)].map(() => false));
dp[0][0] = true;
```
#### 结果
状态`dp[i][j]`代表的是`s`的前`i`位能被`p`的前`j`位匹配，因此结果为
```JavaScript
dp[s.length - 1][p.length - 1]
```
### 完整题解
```JavaScript
var isMatch = function (s, p) {
    s = ' ' + s;
    p = ' ' + p;
    // 定义全为 false 的二维数组, dp[i][j] 表示 s 的前 i 个字符能否被 p 的前 j 个字符匹配。
    const dp = [...new Array(s.length)].map(() => new Array(p.length).fill(false));
    dp[0][0] = true;

    for (let i = 0; i < s.length; i++) {
        for (let j = 1; j < p.length; j++) {
            // 若为 *，p[j] 可以出现0次，不匹配s[i]，即 dp[i][j] = dp[i][j - 1]
            // 也可以匹配掉 s[i], 即 dp[i][j] = dp[i - 1][j] 
            if (p[j] === '*') {
                dp[i][j] = dp[i][j - 1] || (i > 0 && dp[i - 1][j]);
            } else {
                const match = i > 0 && (p[j] === s[i] || p[j] === '?');
                dp[i][j] = match && dp[i - 1][j - 1];
            }
        }
    }
    // console.log('dp', dp);
    return dp[s.length - 1][p.length - 1];
};
```