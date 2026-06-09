### 解题思路
坐标间的间隔由于有对角线走法而简化为两个坐标值的差较大者为最短路径，此处使用绝对值方便后续步数计算。

### 代码

```javascript
/**
 * @param {number[][]} points
 * @return {number}
 */
var minTimeToVisitAllPoints = function(points) {
    let quickpath = 0
    for (let i = 0 ; i < points.length ; i ++) {
        if (points[i+1]){
            let shiftxStep = Math.abs(points[i+1][0] - points[i][0])
            let shiftyStep = Math.abs(points[i+1][1] - points[i][1])
            quickpath += shiftxStep>shiftyStep? shiftxStep : shiftyStep
        }
    }
    return quickpath
};
```