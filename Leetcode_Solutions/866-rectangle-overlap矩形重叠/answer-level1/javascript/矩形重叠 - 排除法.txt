### 解题思路
排除不重叠的情况  rec2 在 rec1 的 上，右，下，左

### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */

// 排除不重叠的情况  rec2 在 rec1 的 上，右，下，左
var isRectangleOverlap = function(rec1, rec2) {
    const [x1, y1, x2, y2] = rec1
    const [m1, n1, m2, n2] = rec2
    return !(  y2 <= n1 || x2 <= m1 || y1 >= n2 || x1 >= m2   )
};
```