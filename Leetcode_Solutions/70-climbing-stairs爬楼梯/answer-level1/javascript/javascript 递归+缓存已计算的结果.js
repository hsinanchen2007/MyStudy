### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
let tmp = []
var climbStairs = function(n) {
    if (n === 2) return 2;
    if (n === 1) return 1;
    //  已计算的结果缓存起来
    if (tmp[n]) {
        return tmp[n] 
    } else {
        tmp[n] = climbStairs(n - 1) + climbStairs(n - 2)
    }
    return climbStairs(n - 1) + climbStairs(n - 2)
};
```