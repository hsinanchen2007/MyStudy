### 解题思路
动态规划，用 dp[i] 表示 s.substring(0, i) 的解码种类数：

- s[i] === '0':
-   if  s[i-1] !== '1' && s[i-1] !== '2': return 0
-   dp[i+1] = dp[i-1]
- s[i-1] === '1' ||  (s[i-1] === '2' && s[i] < '7'):
-   dp[i+1] = do[i] + dp[i-1]
- else:
-   dp[i+1] = dp[i]

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
    if (!s.length || s[0] === '0') return 0;
    const dp = new Array(s.length+1);
    dp[0] = 1;
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === '0') {
            if (s[i-1] !== '1' && s[i-1] !== '2') return 0;
            dp[i+1] = dp[i-1];
        } else if (s[i-1] === '1' || (s[i-1] === '2' && s[i] < '7')) {
            dp[i+1] = dp[i-1] + dp[i];
        } else {
            dp[i+1] = dp[i];
        }
    }
    return dp[s.length];
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)