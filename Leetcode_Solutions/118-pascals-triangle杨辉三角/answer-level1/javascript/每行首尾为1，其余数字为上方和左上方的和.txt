
按行添加，每行个数=行数+1 即 `j <= i`
每行首尾都为1，其余数字为上方和左上方的和`result[i-1][j] + result[i-1][j-1])`
```javascript
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    if (!numRows) return [];
    let result = [];
    for (let i = 0; i < numRows; i ++) {
        let row = [];
        for (let j = 0; j <= i; j ++) {
            row.push(j == 0 || j == i ? 1 : result[i-1][j] + result[i-1][j-1]);
        }
        result.push(row);
    }
    return result;
};
```
