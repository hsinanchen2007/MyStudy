### 解题思路
JS，考虑不重叠

![image.png](https://pic.leetcode-cn.com/3d5074ba765e8e55c3f5f3c244e35ed3bcc90c3e3e7c96f0db2c4e85b4a722d6-image.png)

### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function (rec1, rec2) {
    if ((rec1[2] <= rec2[0]) || (rec2[2] <= rec1[0]) || (rec1[3] <= rec2[1]) || (rec2[3] <= rec1[1])) {
        return false;
    }
    return true;
};
```