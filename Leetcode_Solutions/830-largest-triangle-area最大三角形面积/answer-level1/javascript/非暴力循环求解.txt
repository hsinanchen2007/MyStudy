看到大部分的题解都是暴力循环遍历然后求面积；
如果在点特别多的时候会做很多无效的计算，因为最大面积的点只能存在于最外围的点，所以可以在遍历前先筛除掉一部分点。

```
var largestTriangleArea = function(points) {
    let xMin = -Infinity, xMax = Infinity,
        yMin = -Infinity, yMax = Infinity
    points.forEach(p => {
        let [x, y] = p
        xMin = Math.min(xMin, x)
        xMax = Math.max(xMax, x)
        yMin = Math.min(yMin, y)
        yMax = Math.max(yMax, y)
    })
    points = points.filter(p => {
        let [x, y] = p
        return [xMin, xMax].includes(x) >= 0 || [yMin, yMax].includes(y) >= 0
    })
    return getMin(points)

    function area(p1, p2, p3) {
        let dx1 = p2[0] - p1[0]
        let dx2 = p3[0] - p1[0]
        let dy1 = p2[1] - p1[1]
        let dy2 = p3[1] - p1[1]
        return Math.abs(dx1 * dy2 - dx2 * dy1) / 2
    }
    function getMin(arr) {
        let len = arr.length, res = 0
        for (let i = 0; i < len - 2; ++i) {
            for (let j = i + 1; j < len - 1; ++j) {
                for (let k = j + 1; k < len; ++k) {
                    res = Math.max(res, area(points[i], points[j], points[k]))
                }
            }
        }
        return res
    }
};
```

