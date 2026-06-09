### 解题思路
n & (n - 1) 快速查询1的个数

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    let res = x ^ y, num = 0
    while(res){
        res = res & (res - 1)
        num++
    }
    return num
};
```