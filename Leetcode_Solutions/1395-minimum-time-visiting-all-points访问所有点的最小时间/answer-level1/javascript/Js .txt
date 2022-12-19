### 解题思路
切比雪夫距离： 两点之间的距离定义为其各座标数值差绝对值的最大值。以(x1,y1)和(x2,y2)二点为例，其切比雪夫距离为max(|x2-x1|,|y2-y1|)。

单次移动距离最大即移动时间最小。

### 代码

```javascript
/**
 * @param {number[][]} points
 * @return {number}
 */
var minTimeToVisitAllPoints = function (points) {
  let total = 0;
  for (let i = 0; i < points.length - 1; i++) {
    let x = Math.abs(points[i + 1][0] - points[i][0]);
    let y = Math.abs(points[i + 1][1] - points[i][1]);

    total += Math.max(x, y);
  }
  return total;
};
```