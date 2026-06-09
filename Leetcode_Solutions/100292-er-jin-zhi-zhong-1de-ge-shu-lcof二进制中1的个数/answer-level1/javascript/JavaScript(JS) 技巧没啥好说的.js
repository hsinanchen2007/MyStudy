### 解题思路
剑指offer方法：n与n-1做与运算，可以把n左右边的数字1置0.

### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function (n) {
    let count = 0;
    while (n) {
        count++;
        n = (n - 1) & n;
    }
    return count
};
```