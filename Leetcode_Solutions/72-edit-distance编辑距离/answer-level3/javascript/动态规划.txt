### 解题思路
题目看上去好像不简单，但我们仔细分析之后，可以看出满足动态规划的条件。

假如用 dp[i][j] 表示 word1 的前 i 位 和 word2 的前 j 位之间的最少操作数。
那么考虑以下两种情况：
- word1[i-1] === word2[j-1] （即 word1 的第 i 位和 word2 的第 j 位相同）:
  可以从以下两种情况经过一步操作使得 word1 的前 i 位 和 word2 的前 j 位相同：
    - word1 的前 i - 1 位通过 dp[i-1][j] 次转变后和 word2 的前 j 位相同，增加一位
    - word1 的前 i 位通过 dp[i][j-1] 次转变后和 word2 的前 j - 1 位相同，删除一位

- word1[i-1] !== word2[j-1]：
  可以从以下三种情况经过一步操作使得 word1 的前 i 位 和 word2 的前 j 位相同：
    - word1 的前 i - 1 位通过 dp[i-1][j] 次转变后和 word2 的前 j 位相同，增加一位
    - word1 的前 i 位通过 dp[i][j-1] 次转变后和 word2 的前 j - 1 位相同，删除一位
    - word1 的前 i - 1 位通过 dp[i-1][j-1] 次转变后和 word2 的前 j - 1 位相同，替换一位

边界情况：
    - dp[i][0] := i （删除 i 位）
    - dp[-][j] := j （增加 j 位）


### 代码

```javascript
/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    const m = word1.length, n = word2.length;
    if (!m) return n;
    if (!n) return m;
    const dp = new Array();
    for (let i = 0; i <= m; ++i) {
        let temp = new Array();
        for (let j = 0; j <= n; ++j) {
            temp.push(0);
        }
        dp.push(temp);
    }
    for (let i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (let j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (word1[i-1] === word2[j-1]) {
                dp[i][j] = 1 + Math.min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1] - 1);
            } else {
                dp[i][j] = 1 + Math.min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
};
```

### 复杂度
- 时间复杂度 O(MN)
- 空间复杂度 O(MN)