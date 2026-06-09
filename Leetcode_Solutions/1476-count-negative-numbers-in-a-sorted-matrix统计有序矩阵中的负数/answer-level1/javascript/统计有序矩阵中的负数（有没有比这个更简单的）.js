### 解题思路
投机取巧罢了，一句话搞定

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function(grid) {
    return (count = grid.toString().match(/-/g)) ? count.length : 0
};
```