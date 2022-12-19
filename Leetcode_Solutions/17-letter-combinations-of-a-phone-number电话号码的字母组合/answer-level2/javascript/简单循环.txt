```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
  let dig = {
    "1": [],
    "2": ["a", "b", "c"],
    "3": ["d", "e", "f"],
    "4": ["g", "h", "i"],
    "5": ["j", "k", "l"],
    "6": ["m", "n", "o"],
    "7": ["p", "q", "r", "s"],
    "8": ["t", "u", "v"],
    "9": ["w", "x", "y", "z"]
  }

  let len = digits.length;
  let t = dig[digits[len - 1]] || [];
  for (let i = len - 2; i >= 0; i--) {
    let d = dig[digits[i]];
    let t1 = [];
    for (let dVal of d) {
      for (let tVal of t) {
        t1.push(dVal + tVal);
      }
    }
    t = t1;
  }
  return t;
};
```