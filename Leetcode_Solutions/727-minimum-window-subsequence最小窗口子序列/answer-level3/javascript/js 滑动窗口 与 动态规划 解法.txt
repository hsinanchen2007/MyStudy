

### [727\. 最小窗口子序列](https://leetcode-cn.com/problems/minimum-window-subsequence/)

Difficulty: **困难**


给定字符串 `S` and `T`，找出 `S` 中最短的（连续）**子串** `W` ，使得 `T` 是 `W` 的 **子序列** 。

如果 `S` 中没有窗口可以包含 `T` 中的所有字符，返回空字符串 `""`。如果有不止一个最短长度的窗口，返回开始位置最靠左的那个。

**示例 1：**

```
输入：
S = "abcdebdde", T = "bde"
输出："bcde"
解释：
"bcde" 是答案，因为它在相同长度的字符串 "bdde" 出现之前。
"deb" 不是一个更短的答案，因为在窗口中必须按顺序出现 T 中的元素。
```

**注：**

*   所有输入的字符串都只包含小写字母。All the strings in the input will only contain lowercase letters.
*   `S` 长度的范围为 `[1, 20000]`。
*   `T` 长度的范围为 `[1, 100]`。

#### 解题思路
1. 同时遍历 `S` 和 `T`，如果 `S[i] === T[j]`，那么就 `++i` 和 `++j`，否则就只 `++i`
2. 如果 `j === T.length`，则说明已经找到了符合要求的子串，此时符合要求的子串的右边界就是`i`，由于要找一个最小的区间，所以左边界的值肯定是`T`的第一个字符，即`T[0]`，但是如何确定这个`T[0]` 在`S`中的位置呢，我们可以从右边界`i`的位置往左找
3. 我们从又向左同时遍历 `S` 和 `T`，在`S`中先找出`T`中第一个字符后面的所有字符，然后继续向左遍历，当找到`T`中第一个字符时，就停止遍历，此时的位置就当前最小窗口的左边界位置
4. 记录下这个解的左边界位置，及其窗口的大小，然后从这个解的左边界的下一个位置开始，重复上面的逻辑，继续找下一个符合要求的解
5. 每当找到一个符合要求的解后，比较其窗口的的大小，保留窗口较小的那个解
6. 最后根据窗口最小解的左边界及其长度，从`S`中截取子串并返回


#### Solution

Language: **JavaScript**

##### 滑动窗口解法

```javascript
​/**
 * @param {string} S
 * @param {string} T
 * @return {string}
 */
var minWindow = function(S, T) {
    let i = 0, j = 0, start = -1, minLen = Infinity;
    while (i < S.length) {
        if (S[i] === T[j]) {
            if (++j === T.length) {
                let end = i + 1;
                while (--j >= 0) {
                    while (S[i--] != T[j]);
                }
                i++, j++;
                if (end - i < minLen) {
                    minLen = end - i;
                    start = i
                }
            }
        }
        i++;
    }
    return start === -1 ? "" : S.substr(start, minLen)
};
```

##### 动态规划解法

```js
/**
 * @param {string} S
 * @param {string} T
 * @return {string}
 */
// dp[i][j] = index 表示T[0:j] 是 S[index: i] 的子串
// if S[i] === T[j] dp[i][j] = dp[i-1][j-1]
// else dp[i][j] = dp[i-1][j]
var minWindow = function(S, T) {
    let m = S.length, n = T.length, minLen = Infinity, start = -1;
    let dp = Array.from({length: m+1}, _ => Array(n + 1));
    for (let i = 1; i < n + 1; i++) dp[0][i] = -1;
    for (let i = 1; i < m + 1; i++) dp[i][0] = i;
    dp[0][0] = 0;
    for (let i = 1; i < m + 1; i++) {
        for (let j = 1; j < n + 1; j++) {
            if (S[i - 1] === T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (let i = 1; i < m + 1; i++) {
        if (dp[i][n] < 0) continue;
        if (i - dp[i][n] + 1 < minLen) {
            minLen = i - dp[i][n];
            start = dp[i][n];
        }
    }
    return (start != -1) ? S.substr(start, minLen) : "";
};
```
