### 解题思路
首先反转字符串，找出反转之后的字符串位置，当反转之前的子串等于反转之后该位置上的子串则判断为一个回文子串

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
    let s2 = s.split('').reverse().join('');
    let sum = 0;
    const len = s.length;
    for (let i = 0; i < len; i++) {
        for (let j = i + 1; j <= len; j++) {
            if (s.substr(i, j - i) === s2.substr(len - j, j - i)) {
                sum += 1
            }
        }
    }
    return sum;
};
```