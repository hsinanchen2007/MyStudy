```javascript []
let options = [[1, 1], [3, 4], [-1, 0]]

var minTimeToVisitAllPoints = function (points) {
    let result = 0
    for (let i = 0; i < points.length - 1; i++) {
        result += Math.max(Math.abs(points[i][0] - points[i + 1][0]), Math.abs(points[i][1] - points[i + 1][1]));
    }
    return result;
};

console.log(minTimeToVisitAllPoints(options))

// 由题意结合题中坐标轴可以看出，坐标轴移动时是可以斜着移动的
// 那么我们在移动的时候，对比计算出一个坐标轴移动到另一个坐标轴的[x, y] 其中的一个最大值即可

```

