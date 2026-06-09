### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var getNoZeroIntegers = function(n) {
    var a = 1;
    var b = n - a;
    while(/0/.test(a.toString()) || /0/.test(b.toString())) {
        b = n - ++a;
    }
    return [a, b];
};
```