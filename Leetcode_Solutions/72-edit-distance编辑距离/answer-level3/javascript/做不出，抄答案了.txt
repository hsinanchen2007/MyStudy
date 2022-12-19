### 解题思路
![image.png](https://pic.leetcode-cn.com/6d514dd315e6fc8f85dc171f8f2a452f1b015784e854f15155ed5daa611ea3fa-image.png)

什么抄袭，抄袭什么？！程序员的事情能叫“抄袭”吗？！这叫“借鉴”，这叫“赏析”，这叫“优化”，这叫“解构重构”。。。呸。
[ε=ε=ε=┏(゜ロ゜;)┛]

### 代码

```javascript
/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function (word1, word2) {
    let dp = [];
    const m = word1.length;
    const n = word2.length;
    if (m * n === 0) return m + n; // if either of 2 words is empty, return the length of other word
    // D[i][j] represents the distance of first i characters of word1 to first j characters of word2

    // boundaries of empty word cases
    for (let i = 0; i <= m; i++) {
        let row = [];
        for (let j = 0; j <= n; j++) {
            if (i === 0) {
                row.push(j);
            } else {
                if (j === 0) {
                    row.push(i);
                } else {
                    row.push(0);
                }
            }
        }
        dp.push(row);
    }

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            let case1 = dp[i - 1][j - 1];
            let case2 = dp[i - 1][j] + 1;
            let case3 = dp[i][j - 1] + 1;
            if (word1.substr(i - 1, 1) != word2.substr(j - 1, 1)) {
                case1++;
            }
            dp[i][j] = Math.min(case1, case2, case3);
        }
    }
    return dp[m][n];
};
```