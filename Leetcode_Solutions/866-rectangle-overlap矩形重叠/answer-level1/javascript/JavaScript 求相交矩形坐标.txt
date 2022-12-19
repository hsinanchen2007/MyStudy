### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function(rec1, rec2) {
    //相交的矩形
    var recx = [];
    //求相交矩形的左下角坐标和右上角坐标
    recx[0] = Math.max(rec1[0],rec2[0]);
    recx[1] = Math.max(rec1[1],rec2[1]);
    recx[2] = Math.min(rec1[2],rec2[2]);
    recx[3] = Math.min(rec1[3],rec2[3]);
    //如果坐标符合左下和右上,则符合矩形条件
    if(recx[0] < recx[2] && recx[1] < recx[3]) return true;
    return false;
};
```