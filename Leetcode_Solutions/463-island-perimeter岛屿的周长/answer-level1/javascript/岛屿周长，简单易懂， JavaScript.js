### 解题思路

思路：分别计算横排的周长与竖排的周长，然后相加即可。
不管是横排还是竖排，周长需要+2的只有一种情况：当前是1，前一个不是1，因为如果前一个也是1，重合的两条边就互相抵消了，等于是+2然后-2；

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
const islandPerimeter = function(grid) {
    let res = 0;
    let lh = grid.length;
    let lv = grid[0].length;
    for (let i = 0; i < lh; i++) {
        for (let j = 0; j < lv; j++) {
            if (grid[i][j]) {
                if (!grid[i][j - 1]) res += 2;
                if (!grid[i - 1] || !grid[i - 1][j]) res += 2;
            }
        }
    }
    return res;
};
```