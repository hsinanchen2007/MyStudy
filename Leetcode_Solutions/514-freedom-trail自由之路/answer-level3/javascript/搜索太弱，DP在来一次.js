### 解题思路
一开始没想明白为什么可以用DP。。。
如果ring中没有相同的字符串，那么贪心就可以做，有了相同的字符如： 'acbedc'
那么对应key='ce'中包含'c'的时候就需要考虑是用第一个c还是第二个c,
用dp[i][j]来表示key的第i个字符用ring中第j个字符所需要的最小步数
### 代码

```javascript
/**
 * @param {string} ring
 * @param {string} key
 * @return {number}
 */
var findRotateSteps = function(ring, key) {
    let dp = []
    dp[0] = []
    for(let i = 0; i < ring.length; i++) {
        if(ring[i] == key[0])
        dp[0][i] = Math.min(i, ring.length - i) + 1
    }
    for(let i = 1; i < key.length; i++) {
        dp[i] = []
        for(let j = 0; j < ring.length; j++) {
            if(ring[j] == key[i])
            for(let k = 0; k < ring.length; k++) {
                if(dp[i-1][k]) {
                    let temp = dp[i-1][k] + 1 + Math.min(Math.abs(k-j), ring.length - Math.abs(k-j))
                    dp[i][j] = dp[i][j] ? Math.min(dp[i][j], temp) : temp
                }
            }
        }
    }
    let ans = Infinity
    for(let i = 0; i < ring.length; i++) {
        if(dp[key.length - 1][i]) ans = Math.min(ans, dp[key.length - 1][i])
    }
    return ans
}
```