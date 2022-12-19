### 解题思路
先将坐标转换为字符串，方便查找
两层遍历，先定下左上和右下两个点，再判断左下右上是否在数组中
缺点耗时久了点

### 代码

```javascript
/**
 * @param {number[][]} points
 * @return {number}
 */
var minAreaRect = function(points) {
  let minArea = Infinity
  // string 格式的 points 数组，方便查找
  const StringPoints = []
  for (const point of points) {
    StringPoints.push(point.join(','))
  }
  for (let i = 0; i < points.length; i++) {
    for (let j = i + 1; j < points.length; j++) {
      const leftTop = points[i]
      const rightBottom = points[j]
      // 判断对角线是否与x轴y轴平行，不判断会超时
      if (leftTop[0] !== rightBottom[0] && leftTop[1] !== rightBottom[1]) {
        const rightTop = rightBottom[0] + ',' + leftTop[1]
        const leftBottom = leftTop[0] + ',' + rightBottom[1]
        // 判断另一条对角线是否在 points 中
        if (StringPoints.includes(rightTop) && StringPoints.includes(leftBottom)) {
          let area = Math.abs(leftTop[1] - rightBottom[1]) * Math.abs(leftTop[0] - rightBottom[0])
          minArea = area < minArea ? area : minArea
        }
      }
    }
  }
  return minArea === Infinity ? 0 : minArea
};
```