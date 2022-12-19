刚开始分别求了 x^m <= bound，  y^n <= bound;  上线 m、n ; 发现当 x 或 y 等于 1 时，i 、j 将无限大，造成超时，
所以限定 i < 20 && j < 20

```js 
var powerfulIntegers = function(x, y, bound) {
    let set = new Set()
    for (let i = 0; Math.pow(x,i) <= bound && i < 20; i++) {
        for (let j = 0; Math.pow(y,j) <= bound && j < 20; j++) {
            let item = Math.pow(x,i) + Math.pow(y,j)
            if (item <= bound) {
                set.add(item)
            }
        }
    }
    return [...set]
};
```

