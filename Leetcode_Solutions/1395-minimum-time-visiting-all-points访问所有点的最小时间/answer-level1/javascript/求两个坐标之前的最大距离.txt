### 解题思路
分为两种情况，两个点的线路是一条直线（直线，斜线）， 两个点之间的路线需要转折的。
发现就是求两个点之间距离的最大值就可以了

### 代码

```javascript
/**
 * @param {number[][]} points
 * @return {number}
 */
var minTimeToVisitAllPoints = function(points) {
    var count = 0;
    for(var i = 0; i < points.length - 1; i++) {
        var point = points[i];
        var next = points[i+1];
        var x = Math.abs(next[0] - point[0]);
        var y = Math.abs(next[1] - point[1]);
        count += Math.max(x,y);
    }
    return count;
};
```