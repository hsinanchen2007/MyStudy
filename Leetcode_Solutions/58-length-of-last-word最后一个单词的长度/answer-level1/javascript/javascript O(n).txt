
```javascript []
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    if (!s.length) return 0;

    let start = end = -1;
    for (var i = s.length - 1; i >= 0; i--) {
        if (end === -1 && s[i] !== ' ') {
            end = i;
        } else if (end !== -1 && start === -1 && s[i] === ' ') {
            start = i;
            break;
        }
    }

    return end - start;
};
```
