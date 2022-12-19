### 解题思路
![image.png](https://pic.leetcode-cn.com/d67fab0b71de54a36a58aa5becad7e7a8d5bab6ffffd21a629c82657bc9bf11a-image.png)
代码很简单，一看就会！

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    return matrix.map(item => item.includes(target)).includes(true);
};
```