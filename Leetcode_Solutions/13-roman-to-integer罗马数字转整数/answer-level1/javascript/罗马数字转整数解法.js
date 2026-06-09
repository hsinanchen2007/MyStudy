### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    var len = s.length;
    var preNum = getValue(s[0]);
    var sum = 0;

    for (var i = 1; i < len; i++) {
        var num = getValue(s[i]);
        if (preNum < num) {
            sum -= preNum;
        } else {
            sum += preNum;
        }

        preNum = num;
    }
    sum += preNum;

    return sum;

    function getValue(code) {
        switch(code) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};
```