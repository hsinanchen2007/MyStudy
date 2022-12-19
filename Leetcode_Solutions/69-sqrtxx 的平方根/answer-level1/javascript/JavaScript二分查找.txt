### 解题思路

简单的二分查找

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    if (x < 2) return x
    let left = 0, right = Math.floor(x / 2), mid, pow
    while (left <= right) {
        mid = Math.floor((left + right) / 2)
        pow = mid ** 2
        if (pow === x) return mid
        if (pow < x) left = mid + 1
        else right = mid - 1
    }
    return right
};
```