1. 建立一个map来存储，记录出现的次数
2. 对原数组进行排序
3. 遍历原数组，当已经被取走了我就不再判断
4. 既然是连续，那么下一个呈现的是递增，判断下一个元素在不在，如果不在返回false
5. 结束返回true

```javascript
var isNStraightHand = function(hand, W) {
  var map = {}
  for (var i = 0; i < hand.length; i++) {
    if (!map[hand[i]]) map[hand[i]] = 0
    map[hand[i]]++
  }
  hand.sort((a, b) => a - b)
  for (var i = 0; i < hand.length; i++) {
    // 访问过的不再访问了
    if (!map[hand[i]]) continue

    var count = W - 1
    var sum = 1
    
    map[hand[i]]--
    while(count > 0) {
      if (!map[hand[i] + sum]) {
        return false
      }
      // 标记我已经取走了
      map[hand[i] + sum]--
      sum++
      count--
    }
  }
  return true
};
```
