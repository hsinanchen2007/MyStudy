### 解题思路

大家好，我是 17

1 先排序
2 从前向后迭代，遇到交叉的就吃进，否则加到结果。
3 最后收尾，把当前的区块加进来

### 代码

```javascript
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
  if(intervals.length<2) return intervals
  intervals.sort((a, b) => {
    return a[0] - b[0]
  })
  let result = []
  let current=intervals[0]
  for (let i = 1; i < intervals.length; i++) {
    if (intervals[i][0] <= current[1]) {
      current[1]=Math.max(intervals[i][1],current[1])
    }
    else {
      result.push(current)
      current=intervals[i]
    }
  }
  result.push(current)
  return result
};
```