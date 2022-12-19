### 解题思路
刚开始没想透彻。其实重叠问题的本质是在考边界问题。
找到重合的边界，在边界之外的则是不重叠部分，取反得出重叠区域。

### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function(rec1, rec2) {
        return !(
            rec2[2] <= rec1[0] ||
            rec2[3] <= rec1[1] ||
            rec1[2] <= rec2[0] ||
            rec1[3] <= rec2[1]
        )
};
```