### 解题思路
将数值映射到地址，碰撞则右移，右移次数即move次数

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    let count = 0
    let hash = []
    for(let num of A) {
        while(hash[num]) {
            count++
            num++
        }
        hash[num] = true
    }
    return count
};
```