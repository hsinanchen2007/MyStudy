```javascript
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
  if (intervals.length <= 1) return intervals;
  intervals = intervals.sort((a, b) => a[0] - b[0]);

  let result = [];
  let t = [...intervals[0]];
  for (let i = 1; i < intervals.length; i++) {
    let l = intervals[i][0], r = intervals[i][1];
    if (l > t[1]) {
      result.push(t);
      t = [...intervals[i]];
    } else {
      if (l < t[0]) t[0] = l
      if (r > t[1]) t[1] = r
    }
  }
  result.push(t);
  return result;
};
```

另：LeetCode-cn 的代码执行效率和LeetCode原版的差别真大……