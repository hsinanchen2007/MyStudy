### 解题思路
计算单个柱体贡献的表面积:
1) 立方体个数为0时，贡献面积为0；
2) 立方体个数大于0时，顶和底贡献两个面，根据四个侧面在前后左右四个方向上的重合计算侧面贡献面积：
当v > nv, 则贡献值为v-nv;
当v<= nv，则贡献值为0;
故贡献值为Math.max(v-nv, 0);
计算四个面的贡献值再加上顶和底贡献值即可得到单个柱体的贡献值，将所有贡献值累加可得总的贡献面积。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    let total = 0;
    let n = grid.length;

    for (let i = 0; i<n; i++) {
        let nn = grid[i].length;
        for (let j = 0; j < nn; j++) {
            let v = grid[i][j],
                left = i-1 >= 0 ? grid[i-1][j] : 0,
                down = i+1 < n ? grid[i+1][j] : 0,
                right = j+1 < nn ? grid[i][j+1] : 0,
                up = j -1 >= 0 ? grid[i][j-1] : 0;
            let current = 0;
            if (v > 0) {
                current += 2;
                current += Math.max(v-left, 0);
                current += Math.max(v-right, 0);
                current += Math.max(v-down, 0);
                current += Math.max(v-up, 0);
            }
            total += current;
        }
    }

    return total;
};
```