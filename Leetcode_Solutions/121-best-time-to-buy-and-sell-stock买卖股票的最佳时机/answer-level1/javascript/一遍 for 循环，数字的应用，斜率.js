核心是对数字的应用，本质也是斜率，答案必定是正斜率的，几段正斜率也可以合并。

**效率：**

内存 35.4MB 左右，打败 92%；用时平均在 70~100ms 之间，最多打败 70%。用时不稳定。优化的话，可以把 length 改为常数，用时降低，内存上升，不过总体性能绝对 OK。

**讲解：**

示例：[10, 11, 12, 9, 20, 8, 9, 10, 8, 30]
操作：👇 （后一个减去前一个）
示例：[1, 1, -3, 11, -12, 1, 1, -1, 21] // max: 22

然后累加，如果 total 小于 0 则 total 归 0，如果 total 大于 max 则设置为 max，最后返回 max 即可。

**代码：**

``` javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  let max = 0
  let total = 0
  for (let i = 1; i < prices.length; i++) {
    total += prices[i] - prices[i - 1]
    if (total < 0) {
      total = 0
    } else if (total > max) {
      max = total
    }
  }
  return max
};
```

**题外话：**

这道题目有次校招的时候第一次见，看到题目的思路就是这个，分析数字之间的关系，但没有要求写也就一直搁置，平时也没有刷题的习惯。今天又碰到了，整理了下思路完全实现，写完一身舒畅。这样的话其实可以实时了，后续加入数据，很方便就知道现在卖掉是不是创造了历史最佳。