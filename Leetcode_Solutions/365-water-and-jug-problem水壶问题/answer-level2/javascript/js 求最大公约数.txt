最大公约数
```js
var canMeasureWater = function(x, y, z) {
    if(x + y < z) return false;
    while(y) [x, y] = [y, x % y];
    return !(z % x);
};
```
