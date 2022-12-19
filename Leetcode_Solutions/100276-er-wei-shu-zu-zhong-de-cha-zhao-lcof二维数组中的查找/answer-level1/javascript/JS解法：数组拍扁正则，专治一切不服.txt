### 解题思路
把数组stringify拍扁，然后直接正则匹配，对于一个能够匹配上的数来说，有以下几种可能：
1. ,数,
2. [数,
3. 数],
4. [数]
按照这几种写一个简单的正则就可以了
时间击败49%，空间击败100%
### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    const str = JSON.stringify(matrix)
    const regexp = new RegExp('\\,' + target + '\\,|\\[' + target + '\\,|\\,' + target + '\\]|\\[' + target + '\\]')
    return regexp.test(str)
};
```