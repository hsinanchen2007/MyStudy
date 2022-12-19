```js
var heightChecker = function(heights) {
    let count = 0
    let heights2 = [...heights]
    heights.sort((a, b) => a - b)
    for(let i = 0; i < heights.length; i++) {
        if (heights[i] !== heights2[i]) {
            count++
        }
    }
    return count
};
```
