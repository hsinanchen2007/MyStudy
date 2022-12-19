```
const BRACKETS = {
  ")": "(",
  "]": "[",
  "}": "{"
};
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  if (s.length % 2 || BRACKETS.hasOwnProperty(s[0])) {
    return false;
  } else if (s.length === 0) {
    return true;
  }

  let stack = [];
  for (let i = 0; i < s.length; i++) {
    const str = s[i];
    if (!BRACKETS.hasOwnProperty(str)) {
      stack.push(str);
    } else {
      const top = stack.pop();
      if (top !== BRACKETS[str]) {
        return false;
      }
    }
  }
  return stack.length === 0;
};
```
