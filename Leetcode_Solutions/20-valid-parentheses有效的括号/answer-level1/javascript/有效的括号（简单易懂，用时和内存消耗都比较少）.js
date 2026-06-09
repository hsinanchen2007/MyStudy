执行用时 :64 ms, 在所有 JavaScript 提交中击败了76.98%的用户
内存消耗 :33.6 MB, 在所有 JavaScript 提交中击败了97.94%的用户

```javascript
var isValid = function(s) {
  var n = s.length;
  var stack = [];

  if (n % 2 !== 0 || [')', ']', '}'].indexOf(s[0]) != -1) {
    return false;
  }
  if (s.length < 1 || !s) {
    return true;
  }

  for (var i = 0; i < n; i++) 
  {
    const c = s[i];
    var item = '';
    if (c === ')') {
      item = stack.pop();
      if (item !== '(') 
        return false;
    } 
    else if (c === ']') 
    {
      item = stack.pop();
      if (item !== '[') 
        return false;
    } 
    else if (c === '}') 
    {
      item = stack.pop();
      if (item !== '{') 
        return false;
    } 
    else stack.push(c);
  }

  return stack.length === 0;
};
```
