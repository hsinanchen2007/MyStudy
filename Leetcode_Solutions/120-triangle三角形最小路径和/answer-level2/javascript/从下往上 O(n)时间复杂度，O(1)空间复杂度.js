```js
var minimumTotal = function(triangle) {
    let len = triangle.length;
    for (let i = len - 2; i > -1; i--) {
        for (let j = 0; j < triangle[i].length; j++) {
            triangle[i][j] = Math.min(triangle[i][j] + triangle[i + 1][j], triangle[i][j] + triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
};
```
