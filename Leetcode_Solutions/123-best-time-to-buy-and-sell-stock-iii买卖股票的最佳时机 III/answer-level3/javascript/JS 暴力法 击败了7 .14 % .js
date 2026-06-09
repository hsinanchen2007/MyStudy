写了一个暴力的破解法，最后艰难的通过了，哈哈哈哈。

思路就是切分成两个小数组，分别使用买卖股票最佳时机I的方法求出利润，并且相加，循环即可。

当然，简单的这样肯定会超时，需要稍微剪掉一些循环。

后续补上DP的，什么时候补看心情了

```javascript
// 执行用时: 9304 ms, 在Best Time to Buy and Sell Stock III的JavaScript提交中击败了7 .14 % 的用户
// 内存消耗: 66.5 MB, 在Best Time to Buy and Sell Stock III的JavaScript提交中击败了6 .67 % 的用户
// 莽就完事儿了，分为两段，分别莽一下，做几个判断剪枝，居然通过了。服气
// 动态规划的方法还没写，后期补上
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let l = prices.length,
    temp, ret = 0;
  for (let i = 0; i < l; i++) {
    //第一次剪枝，如果该分数组没有利润，不进入计算
    if (Math.max(...prices.slice(0, i)) <= prices[0] && Math.max(...prices.slice(i)) <= prices[i]) {} else {
      temp = calu([...prices.slice(0, i), prices[i]]) + calu([...prices.slice(i)])
      if (temp > ret) {
        ret = temp
      }
    }
    // console.log(temp)
  }
  return ret
};
var calu = function (arr) {
  let mr = 0,
    mc = 0,
    ret = 0,
    temp;
  for (let i = 0; i < arr.length; i++) {
    mr = arr[i];
    temp = arr.slice(i);
    // 使用ES6新语法求最大值，应该是提速了，因为我用普通循环是超时的
    mc = Math.max(...temp)
    if (mc - mr > ret) {
      ret = mc - mr
    } 
    // 同样，如果没有利润直接中止循环
    else if (mc - mr < 0) {
      break;
    }
  }
  return ret
}
```