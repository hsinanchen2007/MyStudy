### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
    let rtn = 0;
    let matrix = [];
    for (let i=m;i--;) {
        matrix.push([]);
    }
    const  visit = (x,y) => {
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y]) {
            return;
        }
        matrix[x][y] = 1;
        if (`${x}${y}`.split('').reduce((pre,curr) => (pre + parseInt(curr)),0) <= k) {
            rtn++;
            visit(x, y-1);
            visit(x-1, y);
            visit(x, y + 1);
            visit(x+1, y);
        }
    }
    if (m > 0 && n> 0) {
        visit(0,0);
    }
    return rtn;
};
```