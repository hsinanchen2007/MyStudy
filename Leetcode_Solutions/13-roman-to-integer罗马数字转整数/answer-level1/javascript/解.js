### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {

    let m = {
        'I' : 1,
        'V' : 5,
        'X' : 10,
        'L' : 50,
        'C' : 100,
        'D' : 500,
        'M' : 1000
    }

    let prev = '', ans = 0
    for (const c of s) {
        ans += m[c]
        if (prev && m[c] > m[prev])
            ans -= 2 * m[prev]
        prev = c
    }

    return ans
};
```