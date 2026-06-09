### 解题思路
多次买卖，涉及到最大利益，那就考虑波峰波谷，不能抛弃每次峰谷的收益
所以只要前一次后边的大，就要买进卖出

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  let temp = 0;
  let all = 0;
  for(let i =0 ;i< prices.length; i++){
      if(prices[i] > temp){
          all+= (prices[i] - temp)
      }
      temp = prices[i]
  }
  return (prices.length > 0) ? (all - prices[0]) :0
};
```