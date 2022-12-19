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
    
     // 找到上下左右的边界值
     return !(rec1[2] <= rec2[0] ||
              rec1[1] >= rec2[3] || 
              rec1[0] >= rec2[2] ||
              rec1[3] <= rec2[1]
              );
};
```