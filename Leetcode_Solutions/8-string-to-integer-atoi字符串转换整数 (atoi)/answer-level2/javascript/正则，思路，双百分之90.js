思路：1.字符串匹配，肯定是正则最方便
     2.三种情况是+number，-number，number。  符号可有可无，但是符号后面是数字
```
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function (str) {
    str = str.trimLeft();
    let tmp = str.match(/^\+{0,1}[0-9]+|^\-{0,1}[0-9]+/)
    if (!tmp) {
        return 0;
    } else {
        return parseInt(tmp) > (Math.pow(2, 31) - 1) ? Math.pow(2, 31) - 1 : (parseInt(tmp) < (-Math.pow(2, 31)) ? -Math.pow(2, 31) : parseInt(tmp));
    }
};
```

