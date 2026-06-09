### 代码

> 时间复杂度：O(n)  空间复杂度：O(n)

```javascript
var translateNum = function(num) {
   let s = String(num)
   let len = s.length
   if (len === 0) return 0
   const dp = new Array(len + 1).fill(null)
   dp[0] = 1
   dp[1] = 1
   for (let i = 2; i <= len; i++) {
       if (s[i - 2] !== '0' && ((s[i - 2] - '0') * 10 +(s[i - 1] - '0')) < 26) {
           dp[i] = dp[i - 1] + dp[i - 2]
       } else {
           dp[i] = dp[i - 1]
       }
    } 
    return dp[len]
};
```