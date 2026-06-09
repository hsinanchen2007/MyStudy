### 解题思路
动态规划，dp[i][j] 表示 s1.substring(0, i) 和 s2.substring(0, j) 能交错组成 s3.substring(0, i+j)

- dp[0][0] = true
- dp[i][j] = (dp[i-1][j] && s1[i-1] === s3[i+j-1]) || (dp[i][j-1] && s2[j-1] === s3[i+j-1]);

### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @param {string} s3
 * @return {boolean}
 */
var isInterleave = function(s1, s2, s3) {
    const m = s1.length + 1, n = s2.length + 1;
    if (s3.length !== m + n - 2) return false;
    const dp = [];
    for  (let i = 0; i < m; ++i) {
        const temp = new Array(n);
        dp.push(temp);
    }
    dp[0][0] = true;
    for (let i = 1; i < m; ++i) {
        dp[i][0] = dp[i-1][0] && s1[i-1] === s3[i-1];
    }
    for (let j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j-1] && s2[j-1] === s3[j-1];
    }
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            dp[i][j] = (dp[i-1][j] && s1[i-1] === s3[i+j-1]) || (dp[i][j-1] && s2[j-1] === s3[i+j-1]);
        }
    }
    return dp[m-1][n-1];
};
```

### 复杂度
- 时间复杂度 O(M*N)
- 空间复杂度 O(M*N)