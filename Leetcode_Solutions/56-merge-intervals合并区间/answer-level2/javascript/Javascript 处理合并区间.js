### 解题思路

分析题目：给出一个区间的集合，请合并所有重叠的区间。换句话说，求数轴上的公共区间。

注意几个特殊情况：相同区间可以重复（[1,2], [1,2]）；不是已经排序的区间（[4,5],[1,2]）；区间可以使离散或者连续([1,1], [1,2])。这几个在题目中没有明确说，这是提交出错后发现的案例。

### 代码

```javascript
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
  // 如果是空集合，或者只有一个区间的集合，直接返回原始集合
  const len = intervals.length;
  if (len === 1 || len === 0) {
    return intervals;
  }
  // 首先对区间进行排序
  intervals = intervals.sort((a, b) => {
    return a[0] - b[0];
  });
  // 遍历排序好的区间
  for (let i = 1; i < len ;i++) {
    const item = intervals[i];
    const lastItem = intervals[i - 1];
    if (!item) break;
    if (lastItem[1] >= item[0] && lastItem[1] < item[1]) {
      // 后一个区间的第一位，小于前一个区间的第二位
      const newItem = [lastItem[0], item[1]];
      // 获取公共区间，代替之前两个区间
      intervals.splice(i - 1, 2, newItem);
      i--;
    }
    else if (lastItem[1] >= item[0] && lastItem[1] >= item[1]) {
      // 后一个区间的第二位小于前一个的第二位，直接删除后一个区间
      intervals.splice(i, 1);
      i--;
    }
  }
  return intervals;
};
```

现在用时较多，后面继续优化