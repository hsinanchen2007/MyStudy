### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isOneEditDistance = function(s, t) {
    if(s.length - t.length > 1) {
        return false;
    }
    if(s == t) return false;

    if(s.length == t.length) {
        let diffCount = 0;
        for(let i = 0; i < s.length; i++) {
            if(s[i] != t[i]) diffCount++;
        }
        if(diffCount > 1) return false;
        return true;
    } else {
        let pos = undefined;
        for(let i = 0; i < t.length; i++) {
            if(s[i] != t[i]) {
                pos = i;
                break;
            }
        }
        if(!(pos >= 0)) {
            return true;
        }
        if(s.length == t.length + 1 &&
        s.slice(0, pos) == t.slice(0, pos) &&
        s.slice(pos+1, s.length) == t.slice(pos, t.length)) {
            return true;
        }
        if(s.length == t.length - 1 &&
        s.slice(0, pos) == t.slice(0, pos) &&
        s.slice(pos, s.length) == t.slice(pos+1, t.length)) {
            return true;
        }
        return false;
    }
};
```