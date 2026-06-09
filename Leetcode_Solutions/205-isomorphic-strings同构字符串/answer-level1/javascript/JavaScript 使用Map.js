### 解题思路
使用了两个map,检验s,t互相映射

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    const sLen = s.length
    const tLen = t.length
    if (sLen !== tLen) {
        return false
    }
    if (!sLen && !tLen) {
        return true
    }
    const maps = new Map()
    const mapt = new Map()
    for (let i = 0; i < sLen; i++) {
        const sChar = s[i]
        const tChar = t[i]
        if (!maps.has(sChar)) {
            maps.set(sChar, tChar)
        } else {
            if (maps.get(sChar) !== tChar) {
                return false
            }
        }
        if (!mapt.has(tChar)) {
            mapt.set(tChar, sChar)
        } else {
            if (mapt.get(tChar) !== sChar) {
                return false
            }
        }
    }
    return true
};
```