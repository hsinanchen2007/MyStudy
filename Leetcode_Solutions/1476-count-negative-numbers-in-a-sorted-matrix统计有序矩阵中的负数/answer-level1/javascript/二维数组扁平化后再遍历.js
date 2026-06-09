### 解题思路
emmm不想双循环，就把二维数组变成一维了。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function(grid) {
    let count = 0;
    grid.toString().split(',').map(item=>{
        Number(item) < 0 && count++
    });
    return count;
};
```