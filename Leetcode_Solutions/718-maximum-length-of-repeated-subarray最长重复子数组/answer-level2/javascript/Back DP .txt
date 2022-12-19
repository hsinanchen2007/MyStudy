### 解题思路
![Capture.PNG](https://pic.leetcode-cn.com/917d6b9991371b059f9cd70f768d9509904217f0efe627b432f43dc0ce76359b-Capture.PNG)

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number}
 */
var findLength = function(A, B) {
    var res = 0;

    var dp = new Array(A.length).fill(0);

    for (var i = 0; i < B.length; ++i) {
        for (var j = A.length - 1; j >= 0; --j) {
            if (A[j] === B[i]) {
                if (i === 0) {
                    dp[j] = 1;
                } else {
                    dp[j] = j > 0 ? (dp[j-1] + 1) : 1;
                }
                if (dp[j] > res) { res = dp[j]; }
            } else {
                dp[j] = 0;
            }         
        }
    }
    return res;
};
```