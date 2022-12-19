```
/**
 * @param {string} s
 * @return {boolean}
 */
var repeatedSubstringPattern = function(s) {
const len = s.length;
  for (let i = 0, max = len / 2; i <= max; i++) {
    const item = s.slice(0, i);
    const count = len / item.length;
    if (Number.isInteger(count) && item.repeat(count) === s) {
      return true;
    }
  }
  return false;
};
```