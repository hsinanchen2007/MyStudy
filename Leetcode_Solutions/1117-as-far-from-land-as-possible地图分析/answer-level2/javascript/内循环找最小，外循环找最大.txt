### 解题思路
![image.png](https://pic.leetcode-cn.com/cae7894b49d6eafccc13c6f797e8237c7280ac91dc15b797fee88d2eaf62f669-image.png)

0和1的坐标放两个数组，然后遍历，内循环找最小，外循环找最大。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function(grid) {
    let arr0 = [],
        arr1 = [],
        eachDist = Number.MAX_SAFE_INTEGER,
        dist = 0;

    grid.forEach((row, i) => {
        row.forEach((val, j) => {
            if (val === 0) {
                arr0.push([i, j]);
            } else {
                arr1.push([i, j]);
            }
        });
    });
    if (!arr0.length || !arr1.length) return -1;
    arr0.forEach(pos0 => {
        eachDist = Number.MAX_SAFE_INTEGER;
        arr1.forEach(pos1 => {
            eachDist = Math.min(eachDist, Math.abs(pos0[0] - pos1[0]) + Math.abs(pos0[1] - pos1[1]));
        });
        dist = Math.max(dist, eachDist);
    });
    return dist;
};
```