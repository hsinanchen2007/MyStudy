### 解题思路
考虑不重叠时的位置关系：上下左右
上：y1' >= y2
右：x1' >= x2
下：y2' <= y1
左：x2' <= x1
### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function(rect1, rect2) {

return !((rect1[3]<=rect2[1])||(rect1[2]<=rect2[0])||(rect1[1]>=rect2[3])||(rect1[0]>=rect2[2]));
			
};
```