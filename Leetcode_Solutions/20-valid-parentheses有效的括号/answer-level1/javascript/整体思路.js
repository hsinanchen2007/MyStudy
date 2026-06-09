### 解题思路
1.字符串长度非偶数，返回 false
2.通过 map 以键值对形式存储相应括号规则
3.遍历字符串，遇到左括号入栈，遇到右括号，看此时栈是否为空，为空则返回 false，不为空则从栈中弹一个值，如果与 map.get(s[右括号]) 值不同，返回 false
4.遍历结束，配对完毕栈大小应为 0，不为 0 返回 false
5.完结撒花

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    
  if(s.length % 2 !== 0) return false;

  var stack = [];

  var map = new Map();
  map.set(')', '(');
  map.set(']', '[');
  map.set('}', '{');

  for(let c in s) {
    if(s[c] === '(' || s[c] === '{' || s[c] === '[') {
      stack.push(s[c]);
    } else {
      if(stack.length === 0) return false;
      else {
        if(stack.pop() !== map.get(s[c])) return false;
      }
    }
  }

  if(stack.length !== 0) return false;

  return true;
};
```