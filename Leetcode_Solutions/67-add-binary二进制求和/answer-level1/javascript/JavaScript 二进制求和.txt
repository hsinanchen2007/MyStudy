### 解题思路
根据之前做的数组相加衍生出来的，通过相加的方式，逢2进1。

### 代码

```javascript
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function (a, b) {
    let arr = [];
    let add = 0;
    for (let i = a.length - 1, j = b.length - 1; i >= 0 || j >= 0; i-- , j--) {
        let aS = i >= 0 ? a[i] : 0, bS = j >= 0 ? b[j] : 0;
        var sum = ~~aS + ~~bS + add;
        if (sum >= 2) {
            sum %= 2;
            add = 1;
        } else {
            add = 0;
        }
        arr.unshift(sum);
    }
    if (add === 1) {
        arr.unshift(1);
    }
    return arr.join('');
};
```