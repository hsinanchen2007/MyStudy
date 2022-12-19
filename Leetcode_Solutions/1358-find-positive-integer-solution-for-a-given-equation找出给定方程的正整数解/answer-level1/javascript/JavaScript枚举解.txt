```javascript
/**
 * // This is the CustomFunction's API interface.
 * // You should not implement it, or speculate about its implementation
 * function CustomFunction() {
 *
 *     @param {integer, integer} x, y
 *     @return {integer}
 *     this.f = function(x, y) {
 *         ...
 *     };
 *
 * };
 */
/**
 * @param {CustomFunction} customfunction
 * @param {integer} z
 * @return {integer[][]}
 */
var findSolution = function(customfunction, z) {
    const result = []
    let x = 1
    let y = 1
    customfunction = customfunction.f
    while(customfunction(x, 1) <= z) {
        while(customfunction(x, y) <= z) {
            if (customfunction(x, y) === z) result.push([x, y])
            y++
        }
        y = 1
        x++
    }
    return result
};
```
简单说就是利用了单调递增这个特点，从1，1开始往上遍历
![123.png](https://pic.leetcode-cn.com/1a30f2c4729273b050ee0c483fa4a11b6bc4f43e9f271641b70275068cd40560-123.png)
