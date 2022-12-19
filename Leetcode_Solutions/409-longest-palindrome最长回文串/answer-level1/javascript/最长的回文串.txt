### 解题思路
1.题目要求返回字符串的长度，因此只计数，不用做拼接
2.记录下每个字母出现的次数。
3.若是偶数，直接记录总长度，
4.若是奇数，字符串中心的字母肯定占一个长度，然后将奇数 - 1，再加上中心位置的1，就是最终的长度

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let strArr = s.split('')
    let len = strArr.length,
        count = 0,
        obj = {},
        center = 0;
    let strMap = new Map()
    for (var i = 0; i < len; i++) {
        if (strArr[i] in obj) {
            obj[strArr[i]] = obj[strArr[i]] + 1
        } else {
            obj[strArr[i]] = 1
        }

    }
    Object.keys(obj).forEach((key, value) => {
        if ((obj[key] % 2) === 0) {
            count += obj[key]
        } else {
            // 奇数
            count += obj[key] - 1
            center = 1
        }
    })
    count += center
    return count   
};

// ES6 Map
var longestPalindrome = function(s) {
    let strArr = s.split('')
    let len = strArr.length,
        count = 0,
        center = 0;
    let strMap = new Map();
    for (var i = 0; i < len; i++) {
        if (strMap.has(strArr[i])) {
            strMap.set(strArr[i], strMap.get(strArr[i]) + 1)
        } else {
            strMap.set(strArr[i], 1)
        }

    }
    strMap.forEach((key, value, map) => {
        if (key % 2 === 0) {
            count += key
        } else {
            // 奇数
            count += key - 1
            center = 1
        }
    })
    count += center
    return count
};
```