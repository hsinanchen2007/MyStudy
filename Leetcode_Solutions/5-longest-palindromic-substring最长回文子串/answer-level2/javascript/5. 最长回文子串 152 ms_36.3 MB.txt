```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    const len = s.length;
    if (len < 2) {
        return s;
    }
    let result = s[0];
    for (let i = 0.5, step = 0.5; i < len; i = i + step) {
        const diff = i % 1;
        for (let j = 1; ; j++) {
            const ll = i - j + diff;
            const lr = i + j - diff;
            const vl = s[ll];
            const vr = s[lr];
            if (vl === undefined || vr === undefined || vl !== vr) {
                if (lr - ll - 1 > result.length) {
                    result = s.slice(ll + 1, lr);
                }
                break;
            }
        }
    }
    return result;
};
```