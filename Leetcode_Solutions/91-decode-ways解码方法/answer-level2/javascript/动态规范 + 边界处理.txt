边界情况有点多，递推的公式跟爬楼梯差不多，

主要要注意大于26和0的情况

```
/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function (s) {
    if (s.match(/^0|00/)) return 0;
    dp = [1, 1];
    for (let i = 1; i < s.length; i++) {
        if (s[i] === '0' || s[i-1] === '0') {
            if (parseInt(s[i - 1]) < 3) {
                dp[i + 1] = dp[i - 1];
            } else {
                return 0;
            }
        } else if (parseInt(s[i - 1] + s[i]) > 26) {
            dp[i+1] = dp[i]
        } else {
            dp[i + 1] = dp[i] + dp[i-1]
        }
    }
    return dp[s.length];
};

```
