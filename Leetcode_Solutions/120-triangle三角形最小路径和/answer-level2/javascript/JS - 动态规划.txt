### 解题思路
核心公式 dp(i,j) = Math.min(dp(i-1,j-1),dp(i-1,j))

### 代码

```javascript
/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    let preRow = triangle[0];
    for (let i=1; i< triangle.length; i++) {
        let row = triangle[i];
        let len = row.length;
        row[0] += preRow[0];
        row[len- 1] += preRow[len-2];
        for (let j=1; j< len-1;j++) {
            row[j] += Math.min(preRow[j-1],preRow[j]);
        }
        preRow = row;
    }
    return Math.min(...preRow);
};
```