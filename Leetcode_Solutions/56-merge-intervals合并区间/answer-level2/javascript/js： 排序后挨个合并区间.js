## 思路
首先按每个区间开头大小升序排序

排序后，使用变量tmp保存当前区间

遍历所有区间，每次只会面对两种情况：

1. 当前区间和tmp 相邻或者重叠， 可以合并成一个连续的大区间

2. 当前区间与tmp不重叠， 说明tmp是的独立的区间，添加到结果中

时间复杂度：使用了排序函数， O(nlogn) 

## 代码

```js
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
  if (intervals.length === 0) return [];
  // 按每个区间的开头大小排序
  intervals.sort((a, b) => {
    return a[0] - b[0];
  });
  let res = [];
  let tmp = intervals[0];
  for (let interval of intervals) {
    // 有重叠，可以合并
    if (interval[0] <= tmp[1]) {
      tmp = [ tmp[0], Math.max(interval[1], tmp[1]) ];
    } else { // 无重叠， tmp是独立的区间，记录到结果中
      res.push([].concat(tmp));
      tmp = interval;
    }
  }
  res.push(tmp);// 最后的区间

  return res;
};
```
