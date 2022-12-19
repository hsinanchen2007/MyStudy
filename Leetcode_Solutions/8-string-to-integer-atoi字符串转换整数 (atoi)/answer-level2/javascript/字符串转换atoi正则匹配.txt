正则匹配

```
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function (str) {
    let num = str.match(/^\s*[\+-]?[0-9]+/);
    if (!num) {
        return 0;
    }
    const max = Math.pow(2, 31) - 1;
    const min = Math.pow(-2, 31)
    // 如果追求极致简洁，可以省去上面的错误优先判断，但是每次都要算一次max和min效率不高
    // num = num? num > max ? max: num < min ? min: num: 0;
    num =  num > max ? max: num < min ? min: num;
    return num;
};
```
