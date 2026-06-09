### 解题思路
1. 相交必有一个角处于重叠区域内，每个角含有x和y坐标。
2. 只需要分两种情况，横轴和纵轴，两种情况分别又分为左右和上下。
3. 可以判断相交或不相交,不考虑给出的点是固定角的情况.
4. 比如rec1在rec2的下面，不相交，那么我们只需要判断rec1的右上角的y值小于rec2的左下角y值即可(垂直这两个y坐标画两条直线绝不会相交)



### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function (rec1, rec2) {
    return !(rec1[0] >= rec2[2] || rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1])
};
```