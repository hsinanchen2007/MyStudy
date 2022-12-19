```
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  let type = function(str) {
    if (str === '{' || str === '[' || str === '(') {
      return 'front'
    } else {
      return 'end'
    }
  }
  let match = function(end, front) {
    if (end === '}') {
      return front === '{'
    } else if (end === ']') {
      return front === '['
    } else {
      return front === '('
    }
  }
  let stack = []
  for (let i = 0; i < s.length; i++) {
    if (type(s[i]) === 'front') {
      stack.push(s[i])
    } else {
      if (stack[stack.length - 1] && match(s[i], stack[stack.length - 1])) {
        stack.pop()
      } else {
        console.log(false)
        return false
      }
    }
  }
  if (stack.length === 0) {
    console.log(true)
    return true
  } else {
    console.log(false)
    return false
  }
};
```


