在官方解法基础上，加上了空字符串，字符串长度奇数和已右括号开头的特殊判断。
```javascript []
/**
 * @param {string} 
 * @return {boolean}
 */
var isValid = function (s) {
  let len = s.length;
  let first = s[0];
  if (len === 0) return true;
  // 奇数或右括号开头肯定不符合
  if (len % 2 != 0 || [')', ']', '}'].indexOf(first) != -1) {
    return false
  }
  // 栈，存入第一个字符。
  let stack = [first];
  const MAP = {
    ')': '(',
    ']': '[',
    '}': '{',
  }
  for (let i = 1; i < len; i++) {
    let length = stack.length;
    let top = length > 0 ? stack[length - 1] : null;
    let now = s[i];
    if (MAP[now] === top) {
      stack.pop();
    } else {
      stack.push(now);
    }
  }
  return stack.length === 0
};
```
