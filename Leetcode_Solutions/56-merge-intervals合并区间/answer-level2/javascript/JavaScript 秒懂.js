```
var merge = function (intervals) {
  intervals.sort((a, b) => a[0] - b[0])
  let k = 0
  for (let i = 0; i < intervals.length - 1; i++) {
    // 合并
    if (intervals[k][1] >= intervals[i + 1][0]) {
      intervals[k][1] = Math.max(intervals[i + 1][1], intervals[k][1])
    } else {
      intervals[++k] = intervals[i + 1]
    }
  }
  return intervals.slice(0, k + 1)
};
```
