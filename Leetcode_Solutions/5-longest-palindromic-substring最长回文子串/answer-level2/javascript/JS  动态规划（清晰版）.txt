### 代码

```javascript
var longestPalindrome = function(s) {
    const len = s.length
    if (len === 1) return s
    let start = 0
    let longest = 1
    // 新建二维dp
    const dp = []
    for (let i = 0; i < len; i++) {
        dp[i] = []
    }
    // 初始值--处理单个字符或两个相等的字符
    for (let i = 0; i < len; i++) {
        dp[i][i] = 1
        if (i < len - 1) {
            if (s[i] === s[i + 1]) {
                dp[i][i + 1] = 1
                start = i
                longest = 2
            }
        }
    }
    // 状态转移方程式
    for (let l = 3; l <= len; l++) {
        for (let i = 0; i + l - 1 < len; i++) {
            let j = i + l - 1
            if (s[i] === s[j] && dp[i + 1][j - 1] === 1) {
                dp[i][j] = 1
                start = i
                longest = l
            }
        }
    }
    return s.substr(start, longest)
};
```