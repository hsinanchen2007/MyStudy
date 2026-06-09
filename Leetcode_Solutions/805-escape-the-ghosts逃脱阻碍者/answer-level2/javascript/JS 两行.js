### 解题思路
其实我觉得这道题直接问哪个点离终点近比较好

### 代码

```javascript
/**
 * @param {number[][]} ghosts
 * @param {number[]} target
 * @return {boolean}
 */

let distant = (p1, p2) => Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]); // 算距离
var escapeGhosts = (ghosts, target) => ghosts.filter( ghost => distant(ghost, target) <= distant([0,0],target) ).length == 0;

```