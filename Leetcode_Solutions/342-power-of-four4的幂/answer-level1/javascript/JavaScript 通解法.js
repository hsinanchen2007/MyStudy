### 解题思路
![image.png](https://pic.leetcode-cn.com/8c1700f85ee29afbd141b26f1f682fba2d5fc9962b07625cd51604b64cbbad91-image.png)
![image.png](https://pic.leetcode-cn.com/227a2c8232a4b760f873f0ae9d70e781cd5dba4a7803d71f6eac6e4de77e79a3-image.png)

- 通过log换底公式，即可以解决任何幂函数的问题
### 代码

```javascript
/**
 * @param {number} num
 * @return {boolean}
 */
var isPowerOfFour = function(num) {
    let tmp = Math.log2(num)/Math.log2(4)
    return Number.isInteger(tmp)
}
```