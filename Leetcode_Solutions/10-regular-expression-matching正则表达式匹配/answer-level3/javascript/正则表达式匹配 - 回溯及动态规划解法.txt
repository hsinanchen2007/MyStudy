### 解法一: 回溯
根据题目的意思，我们需要做字符串的匹配，若无特殊的情况`.`及`*`，我们只需要将两个字符串的字符逐一对比即可。在有`.`的情况下，只需在匹配时遇到`.`，就认为其可等于任何一个字符即可。遇到`*`时，我们则需要考虑`*`前面的字符出现零次、一次至多次的情况。

比较直观的方法是使用递归回溯的方式来解题, 在回溯方程中，设`p`的索引为`pIndex`，`s`的索引为`sIndex`:

* 若`p[Index + 1]`为`*`， 我们需要考虑字符出现0次或多次的情况。若`p[Index] === s[Index]`，则`backtrace(s, p, sIndex + 1, pIndex)`，即`p[Index]`至少出现一次。之后还需考虑`backtrace(s, p, sIndex, pIndex + 2)`的情况，即`p[Index]`不匹配当前的字符。
* 若`p[pIndex + 1]`不为`*`，则只需考虑当前的`s[sIndex]`与`p[pIndex]`是否匹配，若匹配则继续`backtrace(s, p, sIndex + 1， pIndex + 1)`。
* 若`sIndex`大于`s`的长度，且`pIndex`大于`p`的长度，匹配成功。
* 若`pIndex`大于`p`的长度，而`sIndex`小于`s`的长度，则`p`无法完全匹配`s`。
* 若`sIndex`大于`s`的长度，只需考虑`pIndex`之后必须为`x*`的组合，即后续字符可出现0次，才可匹配。



#### 回溯法题解
    执行用时 :148 ms, 在所有 javascript 提交中击败了29.42%的用户 
```JavaScript []
var isMatch = function (s, p) {
    const backtrace = (s, p, sIndex, pIndex) => {
        // 若 s 及 p 字符已经匹配完
        if (sIndex >= s.length && pIndex >= p.length) {
            return true;
        }
        // 若 pattern 已经匹配完，而 s 还有剩余字符，即当前 pattern 无法匹配所有的字符，返回错误
        if (pIndex >= p.pIndex) {
            return false;
        }
        // 若 s 已经匹配完，p 还有剩余字符，那么 p 剩余的字符串必须为 `x*` 的组合才是正确的答案（出现0次）。
        if (sIndex >= s.length) {
            while (pIndex + 1 < p.length && p[pIndex + 1] === '*') {
                pIndex += 2;
            }
            if (pIndex >= p.length) {
                return true;
            } else {
                return false;
            }
        }
        // 正常情况下，若 p[pIndex] 后一字符为 `*`
        if (pIndex + 1 < p.length && p[pIndex + 1] === '*') {
            // 考虑 p[pIndex] 与当前字符相等并匹配当前的字符的情况，即至少出现一次的情况
            if (sIndex < s.length && (s[sIndex] === p[pIndex] || p[pIndex] === '.') && backtrace(s, p, sIndex + 1, pIndex)) {
                return true;
            }
            // 考虑 p[pIndex] 出现0次的情况
            if (backtrace(s, p, sIndex, pIndex + 2)) {
                return true;
            }
            return false;
        } else {
            // 若 p[pIndex + 1] 不为 *，则如果 p[pIndex] === s[sIndex],继续匹配 sIndex + 1, pIndex + 1。
            if (s[sIndex] === p[pIndex] || p[pIndex] === '.') {
                return backtrace(s, p, sIndex + 1, pIndex + 1);
            } else {
                return false;
            }
        }
    }

    return backtrace(s, p, 0, 0);
};
```

### 题解二：动态规划
#### 状态
首先我们需要一个记录状态的二维数组`dp`，`dp[i][j]`代表`s`的前`i`个字符被`s`的前`j`个字符匹配，若为`true`，则可匹配，若为`false`，则不能匹配。
#### 转移方程
我们定义了状态`dp`，接着我们需要定义状态转移方程，即如何确定`dp[i][j]`的值为`true`或者`false`。在动态规划中，我们通常是从前往后确定状态，也可以从后往前确定。在这里我们假设已知`dp[i][j]`之前的状态，，并且得知`s[i]`, `p[j]`, `dp[i][j]`的可能性有下面几个。

* 首先若`p[j] === *`，在这种情况下我们`p[j - 1]`可以出现0次或者多次:
    * 若`p[j - 1]`出现0次，此时`dp[i][j]`的值应该与`dp[i][j - 2]`的值相同，即只需考虑`s`的前`i`个字符能否被`p`的前`j-2`个字符匹配。
    * 若`p[j - 1]`匹配当前的`s[i]`，此时`dp[i][j]`的值应该等于`dp[i - 1][j]`的值，即只需考虑`s`的前`i - 1`个字符能否被`p`的前`j`个字符匹配，因当前的`s[i]`已经匹配成功了，不影响`dp[i - 1][j]`的结果。
* 若`p[j] !== *`，此时为正常的字符匹配，只需考虑`p[i]`是否匹配`s[i]`，若匹配，则`dp[i][j] = dp[i - 1][j -1]`，否则`dp[i][j] = false`。

上面的状态转移方程转换成代码便是
```JavaScript
if (p[j] === '*') {
    dp[i][j] = dp[i][j - 2] || (i > 0 && (p[j - 1] === s[i] || p[j - 1] === '.') && dp[i - 1][j]);
} else {
    const firstMatch = p[j] === s[i] || p[j] === '.';
    dp[i][j] = firstMatch && dp[i - 1][j - 1];
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

#### 动态规划完整题解
    执行用时 :72 ms, 在所有 javascript 提交中击败了98.75%的用户
    内存消耗 :37.5 MB, 在所有 javascript 提交中击败了12.36%的用户
```JavaScript []
var isMatch = function (s, p) {
    // 在字符串s及模式串p前添加空格，目的是为了初始化 dp[0][0] = true以及方便处理出现 i - 1、j - 1 的情况。
    s = ' ' + s;
    p = ' ' + p;
    // 定义全为 false 的二维数组, dp[i][j] 表示 s 的前 i 个字符能否被 p 的前 j 个字符匹配。
    const dp = [...new Array(s.length)].map(() => [...new Array(p.length)].map(() => false));
    // 初始化 dp[0][0] 为 true，首位都为空字符。
    dp[0][0] = true;
    for (let i = 0; i < s.length; i++) {
        // j 从1开始是因为 dp[0][0] = true，同时dp[i][0]都为false。若从 1 开始，需要添加特别判断 if (i === 0 && j === 0) { continue; }
        for (let j = 1; j < p.length; j++) {
           if (p[j] === '*') {
                // 若 p[j] 为 * 号，则 dp[i][j] 可等于 dp[i][j - 2]，即只需考虑s的前i个字符能否被p的前j-2个字符匹配。
                // 若 p[j - 1] match s[i]，即只需考虑s的前i - 1个字符能否被p的前j个字符匹配
                dp[i][j] = dp[i][j - 2] || (i > 0 && (p[j - 1] === s[i] || p[j - 1] === '.') && dp[i - 1][j]);
            } else {
                // 若 p[j] match s[i]， dp[i][j] 等于 dp[i - 1][j - 1], 否则为 false。
                const firstMatch = i > 0 && (p[j] === s[i] || p[j] === '.');
                dp[i][j] = firstMatch && dp[i - 1][j - 1];
            }
        }
    }
    return dp[s.length - 1][p.length - 1];
};
```