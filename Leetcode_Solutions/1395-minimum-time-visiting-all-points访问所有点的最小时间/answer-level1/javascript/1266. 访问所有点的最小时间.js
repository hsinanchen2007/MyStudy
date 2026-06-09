### 解题思路
两点之间需要的时间就是x, y坐标差的绝对值中较大的那个值

### 代码

```javascript
/**
 * @param {number[][]} points
 * @return {number}
 */
var minTimeToVisitAllPoints = function (points) {
    let result = 0
    for (let i = 0; i < points.length - 1; i++) {
        let x = Math.abs(points[i + 1][0] - points[i][0])
        let y = Math.abs(points[i + 1][1] - points[i][1])
        result += Math.max(x, y)
    }
    return result
};
```