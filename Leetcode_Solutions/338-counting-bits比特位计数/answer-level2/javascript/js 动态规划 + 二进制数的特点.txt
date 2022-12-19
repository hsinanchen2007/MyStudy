![image.png](https://pic.leetcode-cn.com/4847c5bf36f330536e3247a0f854150cd7e901b7a00f365f6f8bede8c9e26964-image.png)

### 解题思路
```js
  动态规划，参考作者「duadua」
  
  二进制数的特点：
  奇数：它的 1 比 「比自己小 1 的数的 1」 多 1 
  偶数：它的 1 和 「自己 / 2」的数的 1 一样多，因为只是去掉了末位的 0
  
  所以对于奇数和偶数的动态转移方程：
  dp[odd] = dp[odd - 1] + 1
  dp[even] = dp[even / 2]
```

### 代码

```javascript
/**
 * @param {number} num
 * @return {number[]}
 */

var countBits = function(num) {
  let dp = new Array(num + 1);
  
  dp[0] = 0;
  
  for (let i = 1; i <= num; i++) {
    if (i & 1) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = dp[i / 2];
    }
  }
  
  return dp;
};
```