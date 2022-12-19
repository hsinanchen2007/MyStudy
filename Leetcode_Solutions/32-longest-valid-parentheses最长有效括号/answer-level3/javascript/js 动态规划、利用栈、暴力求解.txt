

### [32\. 最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)

Difficulty: **困难**


给定一个只包含 `'('` 和 `')'` 的字符串，找出最长的包含有效括号的子串的长度。

**示例 1:**

```
输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
```

**示例 2:**

```
输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
```


#### Solution

Language: **JavaScript**

#### 解法一——暴力求解（超时）

```javascript
​/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let maxLen = 0;
    function valid (i, j) {
        let stack = [];
        while (i < j) {
            if (s[i++] === '(') {
                stack.push(')')
            } else {
                if (stack.length === 0) return false;
                stack.pop()
            }
        }
        return stack.length === 0;
    }
    for (let i = 0; i < s.length; i++) {
        for (let j = i + 2; j <= s.length; j += 2) {
            if (valid(i, j)) {
                if (j - i > maxLen) {
                    maxLen = j - i
                }
            }
        }
    }
    return maxLen
};
```

**时间复杂度：** O(N * N)
**时间复杂度：** O(N)

#### 解法二—— 动态规划

**解题思路：**
1. 定义 dp table，`dp[i]` 为字符串 `s` 0 - i 的最长有效子字符串的长度
2. 定义 dp 方程
   - 当 `(s[i] == ')'` 时
     - 如果 `s[i - 1] == '('`，那么 `dp[i] = dp[i - 2] + 2`
     - 如果 `s[i - 1] == ')'`，那么还要判断 `dp[i - 1]`的有效子字符串之前的字符是否为'('，如果是，则 `dp[i] = dp[i−dp[i−1]−2] + dp[i−1] + 2`，即`dp[i - 1]`的有效子字符串之前的有效字符串长度 + `dp[i - 1]`的有效子字符串的长度 + 一对括号的长度。这里不用特别考虑`dp[i - 1] = 0`的情况，因为`dp[i - 1] = 0`，说明有效字符串为空字符串，空字符串也是符合要求的
   - 其他情况 `dp[i] = 0`

```js
/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let dp = new Array(s.length).fill(0), ans = 0;
    for (let i = 1; i < s.length; i++) {
        if (s[i] === ')') {
            if (s[i - 1] === '(') {
                dp[i] = i > 1 ? dp[i - 2] + 2 : 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] === '(') {
                dp[i] = ((i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
            }
        }
        ans = Math.max(ans, dp[i])
    }
    return ans;
};
```

**时间复杂度：** O(N)
**时间复杂度：** O(N)

#### 解法三—— 利用栈

```js
/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let stack = [-1], ans = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            stack.push(i)
        } else {
            stack.pop();
            if (stack.length === 0) {
                stack.push(i)
            } else {
                ans = Math.max(ans, i - stack[stack.length - 1])
            }
        }
    }
    return ans;
};
```

**时间复杂度：** O(N)
**时间复杂度：** O(N)
