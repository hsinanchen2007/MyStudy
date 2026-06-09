判断斜率是否相等

```js
var isBoomerang = function(points) {
    const dx = points[1][0] - points[0][0];
    const dy = points[1][1] - points[0][1];
    const ex = points[2][0] - points[0][0];
    const ey = points[2][1] - points[0][1];
    return dx * ey != dy * ex;
};
```

