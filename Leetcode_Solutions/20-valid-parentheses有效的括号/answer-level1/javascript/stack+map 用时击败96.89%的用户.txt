## 思路分析
1. 遍历这个s 字符串，如果碰到左括号('(', '{', '[')做入栈操作
2. 碰到右括号 (')', '}', ']')，就与栈顶元素比较(使用map.get()方法)，为 true 做出栈操作，否则直接return false
3. 遍历结束之后如果栈为空就是一个有效的括号匹配，否则就是一个无效的括号匹配(stack.length === 0)

```javascript
var isValid = function (s) {
  // 方便判断右括号是否与栈顶的括号匹配
  const map = new Map([
    ['}', '{'],
    [']', '['],
    [')', '(']
  ])
  const stack = []
  for (let i = 0; i < s.length; i++) {
    // 第1步
    if (s[i] === '(' || s[i] === '[' || s[i] === '{') {
      stack.push(s[i])
    } else if (s[i] === ')' || s[i] === ']' || s[i] === '}') { // 第2步
      if (map.get(s[i]) === stack[stack.length - 1]) {
        stack.pop()
      } else {
        return false
      }
    }
  }
  return stack.length === 0 // 第3步
}
```