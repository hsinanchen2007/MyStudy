```js
var kClosest = function(points, K) {
    points.sort((a,b)=>(a[0]**2+a[1]**2)-(b[0]**2+b[1]**2));
    return points.slice(0,K);
};
```