js使用正则
```js
/**
 * @param {string} str
 * @return {number}
 */
var strToInt = function(str) {
    let res = str.trim().match(/^([+-]?\d+).*$/);
    if (!res) return 0;
    if (res[1] < -2147483648) return -2147483648;
    else if (res[1] > 2147483647) return 2147483647;
    return res[1];
};
```
