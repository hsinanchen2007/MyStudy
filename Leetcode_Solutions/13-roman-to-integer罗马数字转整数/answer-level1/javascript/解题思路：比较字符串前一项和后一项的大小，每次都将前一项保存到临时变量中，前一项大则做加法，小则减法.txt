### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (str) {
   let roman = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    let result = 0
    for (let i = 0, len = str.length; i < len; i++) {
        // 每次将字符串对应罗马数存入临时变量
        const tmp = roman[str[i]]
        if (i < len - 1 && tmp < roman[str[i + 1]]) { //防止越界
            // 如果前一项小于后一项做减法
            result -= tmp
        } else {
            result += tmp
        }
    }
    return result
};
```