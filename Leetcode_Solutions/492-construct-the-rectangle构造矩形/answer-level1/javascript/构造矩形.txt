```js
var constructRectangle = function(area) {
    let middle = parseInt(Math.sqrt(area));
    let arr = [];
    while(area % middle !== 0) {
        middle++
    }
    arr.push(middle);
    arr.push(area/middle);
    return arr.sort((a, b) => b - a);
};
```

