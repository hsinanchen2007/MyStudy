### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers  = function(matrix) {
    let mins=matrix.map(row=>Math.min(...row));
    let maxs=matrix[0].map((item,col_index)=>Math.max(...matrix.map(row=>row[col_index])));
    return maxs.filter(item=>mins.includes(item))
};
```