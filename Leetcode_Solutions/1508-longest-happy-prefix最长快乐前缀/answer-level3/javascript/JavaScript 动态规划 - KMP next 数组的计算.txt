### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPrefix = function(s) {
    let len = s.length
    let dp = Array(len)
    dp[0] = 0
    for(let i = 1; i<len; i++) {
        let start = dp[i-1]
        while(start > 0 && s[i] !== s[start]) start = dp[start - 1]

        dp[i] = s[start] === s[i] ? start + 1 : 0
    }
    return s.substring(0, dp[len-1])
};
```