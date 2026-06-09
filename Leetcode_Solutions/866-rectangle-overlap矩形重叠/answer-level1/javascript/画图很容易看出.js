### 解题思路
首先要判断两个矩形[a,b,c,d][e,f,g,h]相交的特点
那必然是第二个矩形[e,f,g,h]的左下角坐标(e,f)要在第一个矩形[a,b,c,d]右上角坐标(c,d)之下，因此：e<c && f<d
但仅此还不够，因为可能所谓的第一个矩形，和第二个矩形，只是称呼而已，并不代表第一个矩形位置一定要在第二个矩形左边，也有可能在其右边
所以还要再加个判断，即第一个矩形[a,b,c,d]的左下角坐标也要在第二个矩形[e,f,g,h]的右上角坐标之下，则：a<g && b<h

### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function(rec1, rec2) { 
   return rec1[2]>rec2[0] && rec1[3]>rec2[1] && rec1[0]<rec2[2] && rec1[1]<rec2[3]
};
```