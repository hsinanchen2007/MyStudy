### 解题思路
![image.png](https://pic.leetcode-cn.com/453f6df6755dba8099cda42c6073b695c515fbef4b41515edca78c753ec694b7-image.png)


### 代码

```javascript
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
  var coinChange = function(coins, amount) {
    let hash = {};
    function check(money) {
      if (hash[money]) {return hash[money]};
      if (money < 0) return -1;
      if (!money) return 0;
      let res = Infinity;
      for (let coin of coins) {
        let ans = check(money - coin);
        if (ans === -1) continue;
        res = Math.min(res, ans + 1);
      }
      hash[money] = res !== Infinity ? res : -1;
      return hash[money];
    }
    return check(amount);
  };
```