/**
 * @param {number[][]} points
 * @return {number[][]}
 */
var outerTrees = function(points) {
        if (points.length <= 1)
            return points;
        points.sort((a,b)=>a[0] - b[0] == 0 ? a[1]- b[1] : a[0]- b[0]);
        var  result = [];
        for (var i = 0; i < points.length; i++) {
            while (result.length>= 2 && orientation(result[result.length - 2], result[result.length- 1], points[i]) > 0)
                result.pop();
            result.push(points[i]);
        }
        result.pop();
        for (var i = points.length - 1; i >= 0; i--) {
            while (result.length>= 2 && orientation(result[result.length - 2], result[result.length  - 1], points[i]) > 0)
                result.pop();
            result.push(points[i]);
        }
        return new Array(...new Set(result));
};

function orientation( a,  b,  c) {
    return (a[1] - b[1]) * (c[0] - a[0]) - (a[0] - b[0]) * (c[1] - a[1])
}