### 解题思路

### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function (rec1, rec2) {
    let x = (rec1[2] <= rec2[0] || rec1[0] >= rec2[2]); // x轴坐标不相交
    let y = (rec1[3] <= rec2[1] || rec1[1] >= rec2[3]); // y轴坐标不相交
    return !(x || y); // !(不相交) === 香蕉
};
```