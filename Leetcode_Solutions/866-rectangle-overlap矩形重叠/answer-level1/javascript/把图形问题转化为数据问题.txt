### 解题思路
rec1 = [x1,y1,x2,y2]
rec2 = [m1,n2,m2,n2];
如果想要两个矩形有重叠，只需要同时满足四个条件即可：
x1<m2,y1<n2,x2>m1,y2>n2。
不满足这个条件的，都为不重叠

### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function (rec1, rec2) {

    const isOver = rec1.every((item, i) => {
        return i < 2 ? item < rec2[i + 2] : item > rec2[i - 2];
    });

    return isOver;

};
```