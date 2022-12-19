```js
var generate = function(numRows) {

    var result = [];

    for (var i = 1; i <= numRows; i++) {
        var row = [];

        for (var j = 0; j < i; j++) {
            if(j == 0 || j == i - 1) {
                row.push(1);
            } else {
                row.push(result[i-2][j-1] + result[i-2][j]);
            }
        }
        result.push(row)
    }

    return result;
};

var numRows = 6;
console.log(generate(numRows))
```