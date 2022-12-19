先把杨辉三角求出来，在直接取值
```javascript
/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    if(rowIndex === 0) return [1];
    let triangle = [[1]];
    // 这里和求杨辉三角那里有点差异,这里是小于等于
    for(let rowNum = 1 ; rowNum <= rowIndex; rowNum++) {
        let row = [];
        let subRow = triangle[rowNum-1]
        row.push(1);
        // 重点是要把这里的循环次数想清楚
        for(let i = 1; i < subRow.length; i++) {
            row.push(subRow[i-1]+ subRow[i])
        }
        row.push(1);
        triangle.push(row);
    }
    return triangle[rowIndex]
};
```