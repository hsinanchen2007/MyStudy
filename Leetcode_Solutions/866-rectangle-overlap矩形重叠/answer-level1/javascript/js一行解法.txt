### 解题思路
画个图就能明白了，假设以rec1做参考
rec2的左下角([0],[1])要小于（不能等于）rec1的右上角([2],[3])
**且**
rec2的右上角([2],[3])要大于（不能等于）rec1的左下角([0],[1])

### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function (rec1, rec2) {
    return rec2[0] < rec1[2] && rec2[1] < rec1[3] && rec2[2] > rec1[0] && rec2[3] > rec1[1]
};
```