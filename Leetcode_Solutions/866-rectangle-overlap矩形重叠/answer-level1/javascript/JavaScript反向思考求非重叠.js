### 解题思路
依次判断rec2在rec1左右上下侧的情形，再取反即代表两矩形重叠

### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function(rec1, rec2) {
    const [x1, y1, x2, y2] = rec1;
    const [x3, y3, x4, y4] = rec2;
    //          左侧        右侧        上侧        下侧
    return !(x1 >= x4 || x3 >= x2 || y3 >= y2 || y1 >= y4);
};
```