

### [44\. 通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/)

Difficulty: **困难**


给定一个字符串 (`s`) 和一个字符模式 (`p`) ，实现一个支持 `'?'` 和 `'*'` 的通配符匹配。

```
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
```

两个字符串**完全匹配**才算匹配成功。

**说明:**

*   `s` 可能为空，且只包含从 `a-z` 的小写字母。
*   `p` 可能为空，且只包含从 `a-z` 的小写字母，以及字符 `?` 和 `*`。

**示例 1:**

```
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
```

**示例 2:**

```
输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
```

**示例 3:**

```
输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
```

**示例 4:**

```
输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
```

**示例 5:**

```
输入:
s = "acdcb"
p = "a*c?b"
输入: false
```


#### Solution

Language: **JavaScript**

#### 解法一（动态规划）

**解题思路：**

1. 定义 `dp table`
   - `dp[i][j]` 表示字符串 `s[0:i]` 与字符串 `p[0:j]` 是否匹配
2. 定义 dp 方程
   - `if (s[i] == p[j] || p[j] == '?' ) dp[i][j] = dp[i - 1][j - 1]`
   - `else if (p[j === "*"]) dp[i][j] = dp[i - 1][j] || dp[i][j - 1]`
     - `dp[i - 1][j]` 表示 `'*'` 匹配一个或多个字符
     - `dp[i][j - 1]` 表示 `'*'` 匹配空字符串
   - `else dp[i][j] = false`

**代码**

```javascript
​/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
// dp[i][j] = dp[i - 1][j - 1] if (s[i] == p[j] || p[j] == ? )
// dp[i][j] = dp[i - 1][j] || dp[i][j - 1] if (p[j === "*"])
var isMatch = function(s, p) {
    if (p === "*" || s === p) return true;
    let dp = Array.from(Array(s.length + 1), _ => Array(p.length + 1).fill(false));
    dp[0][0] = true;
    for (let i  = 1; i <= p.length; i++) {
        if (!dp[0][i - 1]) break;
        if (p[i - 1] === '*') dp[0][i] = true;
    }
    for (let i = 1; i <= s.length; i++) {
        for (let j = 1; j <= p.length; j++) {
            if (s[i - 1] === p[j - 1] || p[j - 1] === "?") {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] === "*") {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    return dp[s.length][p.length];
};
```

#### 解法二（回溯）

**解题思路：**

- 遍历字符串 s 和 p
  - `if (s[sIdx] === p[pIdx] || p[pIdx] === '?')`，当前字符匹配成功，`sIdx++` `pIdx++`
  - `else if ( p[pIdx] === '*')`
    - 记录当前匹配 `*` 的位置，`sStarIdx = sIdx;pStarIdx = pIdx++;`
    - 这时先让 `*` 匹配 `0` 个字符，如果匹配 `0` 个字符不成功，则根据之前记录的 `sStarIdx` 和 `pStarIdx` 回溯到这个地方，再让 `*` 匹配 `1` 个字符，如果匹配 `1` 个字符也不成功，则继续回溯回来，匹配 `2` 个字符，以此类推
  - `else if (pStarIdx < 0)`，则说明当前字符串不匹配，并且没有 `*` ，则直接 `return false;`
- 当遍历完后，如果 `p` 中还有多余的字符的话，那么必须都得是 `*` ，否则就匹配不成功，则直接 `return false;`
- 最后 `return true;` 表示匹配成功

**代码**

```javascript
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    let sIdx = 0, pIdx = 0, sStarIdx = -1, pStarIdx = -1;
    while (sIdx < s.length) {
        if (pIdx < p.length && (s[sIdx] === p[pIdx] || p[pIdx] === '?')) {
            sIdx++, pIdx++;
        } else if (pIdx < p.length && p[pIdx] === '*') { //记录如果之后序列匹配不成功时， sIdx和pIdx需要回溯到的位置
            sStarIdx = sIdx;
            pStarIdx = pIdx++; // 将 pIdx++，sIdx不变，表示先让 * 匹配 0 个字符，不行再回溯
        } else if (pStarIdx > -1) { //发现当前字符不匹配且没有星号 但是 pStarIdx > -1 说明可能是 * 之前匹配的字符数量少了 这时回溯，让*匹配的字符增加一个
            sIdx = ++sStarIdx;
            pIdx = pStarIdx + 1;
        } else {
            return false;
        }
    }
    while (pIdx < p.length) if (p[pIdx++] !== '*') return false; //如果 p 中还有多余的字符的话，那必须都是 * 否则 匹配就不成功
    return true;
};
```