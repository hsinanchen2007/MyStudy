![image.png](https://pic.leetcode-cn.com/3b6efa65541433d9f300710f240ef4836d6296970fd5ce21d49d1482b4567792-image.png)

### 解题思路
```js
  首先观察出不重叠的条件：一个矩形完全在另一个矩形的上、下、左、右、侧
  对条件取反即可
```

### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */

var isRectangleOverlap = function(rec1, rec2) {
  return !(rec1[3] <= rec2[1] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3] 
         || rec1[2] <= rec2[0]);
};
```