### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var strToInt = function (str) {
    let INT_MAX = Math.pow(2, 31) - 1;
    let INT_MIN = -Math.pow(2, 31);
    let len = str.length;
    let k = 0;
    //去除空格
    while (k < len && str[k] === ' ') k++;
    let number = 0;
    // 标记正负数
    let is_minus = false;
    if (str[k] === '+') k++;
    else if (str[k] === '-') {
        k++;
        is_minus = true;
    }
    while (k < len && str[k] >= '0' && str[k] <= '9') {
        number = number * 10 + (str[k] - '0');
        k++;
    }
    if (is_minus) number *= -1;
    if (number > INT_MAX) number = INT_MAX;
    if (number < INT_MIN) number = INT_MIN;
    return number;

};
```