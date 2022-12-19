```javascript
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    const hash = {}
    
    let minIndex = null;
    
    let i = 0;
    
    while(i < s.length) {
        if (hash[s[i]] || hash[s[i]] === 0) {
           hash[s[i]]++;
        } else {
           hash[s[i]] = 0;
        }
        i++
    }
    
    while(i-- > 0) {
        if (!hash[s[i]]) {
            minIndex = i;
        }
    }
    if (minIndex === null) return -1;
    return minIndex
};
```