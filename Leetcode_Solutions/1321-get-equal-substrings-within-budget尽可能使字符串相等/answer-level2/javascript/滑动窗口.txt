- 用一个数组dp来维护当前符合要求的子序列
- maxCost表示剩余的钱
- 首先试图添加一个字母   maxCost >= Math.abs(s[i].codePointAt() - t[i].codePointAt()) 就可以加入
- 否则 应该从数组dp的开头开始删除花费的钱  直到能够加入当前字母  或者 无法加入
```
var equalSubstring = function(s, t, maxCost) {
  let dp = [];
  let res = 0;
  for (let i = 0, length = s.length; i < length; ++i) {
    let count = Math.abs(s[i].codePointAt() - t[i].codePointAt());
    if (maxCost >= count) {
      dp.push(count);
      maxCost -= count;
      res = Math.max(dp.length, res);
    } else if (dp.length) {
      while(maxCost < count && dp.length) {
        maxCost += dp.shift()
      }
      if (maxCost >= count) {
        dp.push(count);
        maxCost -= count;
      }
    }
  }
  return res;
};
```
