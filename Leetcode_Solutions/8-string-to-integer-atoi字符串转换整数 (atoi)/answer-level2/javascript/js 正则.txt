正则
```js
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    let res = str.trim().match(/^[+-]?\d+.*$/);
    if (!res) return 0;
    res = parseInt(res[0], 10);
    if (res > 2147483647) return 2147483647;
    if (res < -2147483648) return -2147483648;
    return res;
};
```
