### 解题思路
1、罗马数字除了几种特殊情况下，大的数字会在小的前面
2、所以当前一位数字小于后一位的特殊情况时，即s[i] < s[i + 1]时，在当前数字前加上负号
例： IV = -1 + 5

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    var hashMap = {
        'M': 1000,
        'D': 500,
        'C': 100,
        'L': 50,
        'X': 10,
        'V': 5,
        'I': 1
    };
    var num = 0;
    for(var i = 0; i < s.length; i++) {
        var cur = hashMap[s[i]];
        var next = hashMap[s[i + 1]] || 0;
        cur < next ? num -= cur : num += cur;
    }
    return num;
};
```