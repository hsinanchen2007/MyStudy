

### 代码

```javascript
/**
 * @param {number[][]} points
 * @return {number}
 */
var minTimeToVisitAllPoints = function(points) {
    let count = 0;
    for(let i = 1; i < points.length; i++){
        let step = Math.max(Math.abs(points[i][0]-points[i-1][0]),
                   Math.abs(points[i][1]-points[i-1][1]));
        count += step; 
    }
    return count;
};
```