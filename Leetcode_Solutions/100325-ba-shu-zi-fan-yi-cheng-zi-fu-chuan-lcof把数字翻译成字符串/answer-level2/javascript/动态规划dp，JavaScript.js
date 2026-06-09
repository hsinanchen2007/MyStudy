### 解题思路

用动态规划思想很容易解决这道题

首先每单个字符一定能转换成字母；

如果i字符与i - 1字符能组成字符，那么i处的组成方法就有两种，即i- 1与i- 2两个位置的方法数量之和

如果i字符与i - 1字符不能组成字符，那么i处的组成发只有一种，即i - 1处的方法数量

这里有一个细节，如果i - 2处字符为0，那么i - 1与i处的字符不能算作一个在组成方法，应该按照不能组成来处理

而且如果i<= 1，不存在i - 2，所以+1即可

最后，状态转移方程为：

    dp[i] = dp[i - 1] + if('' + num[i - 1] + num[i] < 26){i > 1 ? dp[i - 2] : 1};

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var translateNum = function(num) {
    // dp  dp[i] = dp[i - 1] + if('' + num[i - 1] + num[i] < 26){i > 1 ? dp[i - 2] : 1};
    num += '';
    const len = num.length;
    let dp = [1];
    for(let i = 1; i < len; i ++) {
        if('' + num[i - 1] + num[i] < 26 && num[i - 1] !== '0') {
            dp[i] = i > 1 ? dp[i - 1] + dp[i - 2] : dp[i - 1] + 1;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    return dp[len - 1];
};
```