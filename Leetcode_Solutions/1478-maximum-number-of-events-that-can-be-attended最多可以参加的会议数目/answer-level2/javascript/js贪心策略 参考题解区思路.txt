![image.png](https://pic.leetcode-cn.com/929d03a51f6f89b0486892b2abfd8f7e4ce4a11be0174852a4ac89ab9038f1be-image.png)

### 解题思路
```js
贪心算法
1.把所有会议按照结束时间排序，我们优先参加早结束的会议
2.由于一天只能参加一个会议，所以使用一个 哈希(数组也可以) 记录我们
  使用过的天
3.参加每一个会议时，优先使用比较早的天来参加
```

### 代码

```javascript
/**
 * @param {number[][]} events
 * @return {number}
 */

var maxEvents = function(events) {
  let count = 0, had = [];
  
  events.sort((a, b) => a[1] - b[1]);
  
  for (let i = 0, len = events.length; i < len; i++) {
    let [start, end] = events[i];
    for (let j = start; j <= end; j++) {
      if (had[j] === undefined) {
        had[j] = 1;
        count++;
        break;
      }
    }
  }
  
  return count;
};
```