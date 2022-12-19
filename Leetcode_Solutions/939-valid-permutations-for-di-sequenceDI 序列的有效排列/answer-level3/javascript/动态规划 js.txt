### 解题思路
动态规划

### 代码

```javascript
/**
 * @param {string} S
 * @return {number}
 */
var numPermsDISequence = function(S) {
    let MOD = 1000000007
    let DP = []
    let len = S.length
    for(let i = 0; i < len + 1; i++) {
        i === 0 && DP.push(new Array(len + 1).fill(1))
        i && DP.push(new Array(len + 1).fill(0))
    }
    // console.log(DP)
    for (let i = 1; i <= len; ++i) {
        for (let j = 0; j <= i; ++j) {
            if (S[i - 1] == 'D') {
                for (let k = j; k < i; ++k) {
                    DP[i][j] += DP[i-1][k];
                    DP[i][j] %= MOD;
                }
            } else {
                for (let k = 0; k < j; ++k) {
                    DP[i][j] += DP[i-1][k];
                    DP[i][j] %= MOD;
                }
            }
        }
    }
    let res = 0
    DP[len].forEach(ele => {
        res += ele
        res %= MOD
    })
    return res
};
```