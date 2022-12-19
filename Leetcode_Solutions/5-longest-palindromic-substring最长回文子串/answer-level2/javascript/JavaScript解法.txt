### 解题思路
本质上就是不停构造子串，判断是否回文，一开始想复杂了，不停地拼两个子串，提效关键在于判断回文的算法

### 代码

```javascript
var longestPalindrome = function(s) {
    let res = ''
    let max = 0
    if (s.length <= 1) {
        return s
    }
    for (let i = 0, len = s.length; i < len; i++) {
        let str = s[i]
        for (let j = i + 1; j < len; j++) {
            str += s[j]
            if(str.length > max && isReverse(str)) {
                res = str
                max = str.length
            }
        }
    }
    if (res === '') {
        return s[0]
    }
    return res
};

function isReverse(str) {
    let flag = false
    if (str[0] !== str[str.length - 1]) return false
    for (let i = 0, len = Math.floor(str.length / 2); i < len; i++) {
        let j = str.length - 1 - i;
        if (str[i] && str[j]) {
            if (str[i] !== str[j]) {
                flag = true;
                break;
            }
        }
    }
    return !flag
}
```