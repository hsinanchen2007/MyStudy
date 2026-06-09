### 解题思路
dp做法

### 代码

```javascript
/**
 * @param {number[][]} envelopes
 * @return {number}
 */
var maxEnvelopes = function(envelopes) {
    if(envelopes.length == 0) return 0
    envelopes.sort((a, b) => {
        if(a[0] == b[0]) {
            return a[1] - b[1]
        }
        return a[0] - b[0]
    })
    // console.log(envelopes)
    let dp = Array(envelopes.length).fill(0)
    dp[0] = 1
    for(let i = 1; i < envelopes.length; i ++){
        for(let j = 0; j < i; j++){
            if(envelopes[i][1] > envelopes[j][1] && envelopes[i][0] != envelopes[j][0]) {
                dp[i] = Math.max(dp[i], dp[j])
            }
        }
        dp[i] += 1
        
    }
    return Math.max(...dp)
};
```