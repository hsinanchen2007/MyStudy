### 解题思路
动态规划解决

### 代码

```javascript
/**
 * @param {number} N
 * @return {boolean}
 */
var divisorGame = function(N) {
    if(N == 1) {
        return false;
    }
    if(N == 2) {
        return true;
    } 
    const dp = new Array(N+1);
    dp[1] = false;
    dp[2] = true;
    for(let i = 3; i <= N; i++){
        dp[i] = false;
        for(let j = 1; j < i; j++){
            // 如果i-j是false，而i本身是true，直接返回true
            if(i % j === 0 && !dp[i - j]){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[N];
};
```