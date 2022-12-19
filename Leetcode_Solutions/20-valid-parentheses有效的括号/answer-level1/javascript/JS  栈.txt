```
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  let pair = {
    '(': ')',
    '{': '}',
    '[': ']',
  }
  let stack = [], top = 0
  for(let i=0; i<s.length; i++){
    if(s[i] === '(' || s[i] === '{' || s[i] === '['){
      stack.push(s[i])
      top++
    }else{
      if(pair[stack[top-1]] !== s[i]){
        return false
      }else{
        stack.pop()
        top--
      }
    }
  }
  return stack.length === 0
};
```
