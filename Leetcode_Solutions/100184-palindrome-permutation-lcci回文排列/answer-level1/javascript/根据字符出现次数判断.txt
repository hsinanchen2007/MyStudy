### 解题思路
简单理解回文串，有且只有一个数量为单数的字符
首先循环处理每个字符串出现次数，再将对应 key 的 value 除余拼成数组
最后判断数组长度大于 1，说明超过回文串限定数

第一次解题，不足指出望大佬们指出，感谢

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var canPermutePalindrome = function(s) {
    var strObj = {},
        strLen = s.length
    for (var i = 0; i < strLen; i++) {
        var key = s[i]
        strObj[key] ? strObj[key]++ : strObj[key] = 1
    }

    let arr = [];
    for (let i in strObj) {
        strObj[i] % 2 === 0 ? '' : arr.push(strObj[i])
    }

    return arr.length > 1 ? false : true
};
```