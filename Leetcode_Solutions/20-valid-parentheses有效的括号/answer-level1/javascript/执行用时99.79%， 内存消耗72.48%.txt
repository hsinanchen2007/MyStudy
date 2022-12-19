### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const map = {
        ')': '(',
        ']': '[',
        '}': '{',
    }
    let ary = [], i = 0,
        keys = Object.keys(map), values = Object.values(map);

    while(i < s.length) {
        let str = s.charAt(i);
        if (values.includes(str)) {
            ary.push(str)
        } else if (keys.includes(str)) {
            if (ary[ary.length - 1] === map[str]) {
                ary.pop()
            } else {
                return false
            }
        }
        i++
    }
    return ary.length < 1
};
```