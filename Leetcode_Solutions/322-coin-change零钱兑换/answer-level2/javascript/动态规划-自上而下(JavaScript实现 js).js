```javascript
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
  if (amount < 1) return 0;
  var count = []
  for(let i = 0; i < amount; i ++) {
    count.push(0)
  }
  return coinchange(coins, amount, count);  
};

function coinchange(coins, rem, count) {
    if (rem < 0) return -1;
    if (rem == 0) return 0;
    if (count[rem - 1] != 0) return count[rem - 1];
    let min = Infinity;
    for (let i = 0; i < coins.length; i ++) {
      let coin = coins[i]
      let res = coinchange(coins, rem - coin, count);
      if (res >= 0 && res < min)
        min = 1 + res;
    }
    count[rem - 1] = (min == Infinity) ? -1 : min;
    return count[rem - 1];
}
```